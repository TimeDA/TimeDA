#include <type_traits>
 #include <utility>
 #include <queue>
 #include <limits>
 #include <iostream>
 #include <functional>
 #include <vector>
 #include <string>
 #include <algorithm>
 namespace lc {
 template <class WeightType, class CapacityType>
 struct EdgeWithWeightAndCapacity {
 	int to;
 	WeightType weight;
 	CapacityType capacity;
 	EdgeWithWeightAndCapacity() : to(0), weight(), capacity() { }
 	EdgeWithWeightAndCapacity(
 		int to, const WeightType &weight, const CapacityType &capacity)
 		: to(to), weight(weight), capacity(capacity)
 	{ }
 };
 }
 namespace lc {
 template <typename EdgeType>
 class AdjacencyList {
 public:
 	typedef std::vector<EdgeType> ListType;
 private:
 	std::vector<ListType> m_lists;
 public:
 	explicit AdjacencyList(int n = 0)
 		: m_lists(n)
 	{ }
 	int size() const { return m_lists.size(); }
 	template <typename... Args>
 	void add_edge(int u, Args&&... args){
 		m_lists[u].emplace_back(args...);
 	}
 	const ListType &operator[](int u) const { return m_lists[u]; }
 	ListType &operator[](int u){ return m_lists[u]; }
 };
 }
 namespace lc {
 template <class EdgeType>
 struct HasWeight {
 private:
 	template <typename U>
 	static auto check(const U &x) -> decltype(x.weight, std::true_type());
 public:
 	static const bool value = decltype(check(EdgeType()))::value;
 };
 }
 namespace lc {
 template <class EdgeType>
 struct ResidualEdge : public EdgeType {
 	int rev;
 	template <class... Args>
 	ResidualEdge(int rev, Args&&... args)
 		: EdgeType(args...)
 		, rev(rev)
 	{ }
 };
 template <class EdgeType>
 class ResidualAdjacencyList
 	: public AdjacencyList<ResidualEdge<EdgeType>>
 {
 public:
 	explicit ResidualAdjacencyList(int n = 0)
 		: AdjacencyList<ResidualEdge<EdgeType>>(n)
 	{ }
 };
 template <class EdgeType>
 auto make_residual(const AdjacencyList<EdgeType> &graph)
 	-> typename std::enable_if<
 		HasWeight<EdgeType>::value, ResidualAdjacencyList<EdgeType>>::type
 {
 	typedef decltype(EdgeType().capacity) capacity_type;
 	const int n = graph.size();
 	ResidualAdjacencyList<EdgeType> result(n);
 	for(int u = 0; u < n; ++u){
 		for(const auto &e : graph[u]){
 			const int v = e.to;
 			const int rev_u = result[v].size();
 			const int rev_v = result[u].size();
 			result[u].emplace_back(rev_u, e);
 			result[v].emplace_back(rev_v, e);
 			result[v].back().to = u;
 			result[v].back().capacity = capacity_type();
 			result[v].back().weight = -e.weight;
 		}
 	}
 	return result;
 }
 }
 namespace lc {
 template <class EdgeType>
 auto mincostflow_primal_dual(
 	int source, int sink, decltype(EdgeType().capacity) flow,
 	ResidualAdjacencyList<EdgeType> &graph)
 	-> decltype(EdgeType().weight)
 {
 	typedef decltype(EdgeType().weight) weight_type;
 	typedef decltype(EdgeType().capacity) capacity_type;
 	typedef std::pair<weight_type, int> weighted_pair;
 	const weight_type inf = std::numeric_limits<weight_type>::max();
 	const int n = graph.size();
 	weight_type result = 0;
 	std::vector<weight_type> h(n);
 	std::vector<int> prev_vertex(n), prev_edge(n);
 	while(flow > 0){
 		std::priority_queue<
 			weighted_pair, std::vector<weighted_pair>,
 			std::greater<weighted_pair>> pq;
 		std::vector<weight_type> dist(n, inf);
 		dist[source] = weight_type();
 		pq.push(std::make_pair(dist[source], source));
 		while(!pq.empty()){
 			weighted_pair p = pq.top();
 			pq.pop();
 			const int u = p.second;
 			if(dist[u] < p.first){ continue; }
 			for(size_t i = 0; i < graph[u].size(); ++i){
 				const auto &e = graph[u][i];
 				if(e.capacity <= 0){ continue; }
 				const int v = e.to;
 				const auto new_dist = dist[u] + e.weight + h[u] - h[v];
 				if(dist[v] <= new_dist){ continue; }
 				dist[v] = new_dist;
 				prev_vertex[v] = u;
 				prev_edge[v] = i;
 				pq.push(std::make_pair(new_dist, v));
 			}
 		}
 		if(dist[sink] >= inf){ return -1; }
 		for(int i = 0; i < n; ++i){ h[i] += dist[i]; }
 		weight_type diff = flow;
 		for(int v = sink; v != source; v = prev_vertex[v]){
 			diff = std::min(
 				diff, graph[prev_vertex[v]][prev_edge[v]].capacity);
 		}
 		flow -= diff;
 		result += diff * h[sink];
 		for(int v = sink; v != source; v = prev_vertex[v]){
 			auto &e = graph[prev_vertex[v]][prev_edge[v]];
 			e.capacity -= diff;
 			graph[v][e.rev].capacity += diff;
 		}
 	}
 	return result;
 }
 }
 using namespace std;
 using Edge = lc::EdgeWithWeightAndCapacity<int, int>;
 static const int INF = 1000000000;
 int main(){
 	ios_base::sync_with_stdio(false);
 	int T;
 	cin >> T;
 	for(int case_num = 1; case_num <= T; ++case_num){
 		int n;
 		cin >> n;
 		const int m = 2 * n;
 		vector<int> a(m), b(m), leave(m), duration(m);
 		vector<vector<int>> in(n), out(n);
 		for(int i = 0; i < m; ++i){
 			int x, y, z;
 			cin >> x >> y >> z;
 			a[i] = i / 2;
 			b[i] = x - 1;
 			leave[i] = y;
 			duration[i] = z;
 			in[b[i]].push_back(i);
 			out[a[i]].push_back(i);
 		}
 		const int source = 2 * m, sink = source + 1;
 		lc::AdjacencyList<Edge> graph(2 * m + 2);
 		for(int i = 0; i < m; ++i){
 			const int arrival = (leave[i] + duration[i]) % 24;
 			for(const int j : out[b[i]]){
 				int cost = 0;
 				if(arrival <= leave[j]){
 					cost += leave[j] - arrival;
 				}else{
 					cost += leave[j] + 24 - arrival;
 				}
 				graph.add_edge(i, j + m, cost, 1);
 			}
 			graph.add_edge(source, i, 0, 1);
 			graph.add_edge(i + m, sink, 0, 1);
 		}
 		auto residual = lc::make_residual(graph);
 		const int wait_sum =
 			lc::mincostflow_primal_dual(source, sink, m, residual);
 		int answer = INF;
 		for(int u = 0; u < m; ++u){
 			for(const auto& e : residual[u]){
 				const int v = e.to;
 				if(v == m && e.capacity == 0){
 					answer = min(answer, wait_sum - e.weight + leave[0]);
 				}
 				if(v == m + 1 && e.capacity == 0){
 					answer = min(answer, wait_sum - e.weight + leave[1]);
 				}
 			}
 		}
 		for(const auto d : duration){
 			answer += d;
 		}
 		cout << "Case #" << case_num << ": " << answer << endl;
 	}
 	return 0;
 }
