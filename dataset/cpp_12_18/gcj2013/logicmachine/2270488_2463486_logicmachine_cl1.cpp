#include <iostream>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 typedef long long ll;
 
 const ll TABLE[] = {
 	0ll,
 	1ll,
 	4ll,
 	9ll,
 	121ll,
 	484ll,
 	10201ll,
 	12321ll,
 	14641ll,
 	40804ll,
 	44944ll,
 	1002001ll,
 	1234321ll,
 	4008004ll,
 	100020001ll,
 	102030201ll,
 	104060401ll,
 	121242121ll,
 	123454321ll,
 	125686521ll,
 	400080004ll,
 	404090404ll,
 	10000200001ll,
 	10221412201ll,
 	12102420121ll,
 	12345654321ll,
 	40000800004ll,
 	1000002000001ll,
 	1002003002001ll,
 	1004006004001ll,
 	1020304030201ll,
 	1022325232201ll,
 	1024348434201ll,
 	1210024200121ll,
 	1212225222121ll,
 	1214428244121ll,
 	1232346432321ll,
 	1234567654321ll,
 	4000008000004ll,
 	4004009004004ll,
 	100000020000001ll,
 	100220141022001ll,
 	102012040210201ll,
 	102234363432201ll,
 	121000242000121ll,
 	121242363242121ll,
 	123212464212321ll,
 	123456787654321ll,
 	400000080000004ll,
 	10000000200000001ll,
 	10002000300020001ll,
 	10004000600040001ll,
 	10020210401202001ll,
 	10022212521222001ll,
 	10024214841242001ll,
 	10201020402010201ll,
 	10203040504030201ll,
 	10205060806050201ll,
 	10221432623412201ll,
 	10223454745432201ll,
 	12100002420000121ll,
 	12102202520220121ll,
 	12104402820440121ll,
 	12122232623222121ll,
 	12124434743442121ll,
 	12321024642012321ll,
 	12323244744232321ll,
 	12343456865434321ll,
 	12345678987654321ll,
 	40000000800000004ll,
 	40004000900040004ll,
 };
 
 int main(){
 	int T;
 	cin >> T;
 	const int TABLE_SIZE = (sizeof(TABLE) / sizeof(ll));
 	for(int caseNum = 1; caseNum <= T; ++caseNum){
 		ll A, B;
 		cin >> A >> B;
 		const ll *pa = lower_bound(TABLE, TABLE + TABLE_SIZE, A);
 		const ll *pb = upper_bound(TABLE, TABLE + TABLE_SIZE, B);
 		cout << "Case #" << caseNum << ": " << (pb - pa) << endl;
 	}
 	return 0;
 }
 
