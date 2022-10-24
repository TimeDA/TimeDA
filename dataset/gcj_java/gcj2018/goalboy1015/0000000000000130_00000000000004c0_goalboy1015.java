import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			PriorityQueue<Party> pq = new PriorityQueue<Party>(
					(party1, party2) -> Integer.compare(party2.number, party1.number));

			int N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				int number = sc.nextInt();
				pq.offer(new Party((char) ('A' + i), number));
			}

			System.out.print("Case #" + tc + ":");

			while (pq.size() > 2) {
				Party party = pq.poll();
				System.out.print(" " + party.letter);

				party.number--;
				if (party.number > 0) {
					pq.offer(party);
				}
			}
			Party party1 = pq.poll();
			Party party2 = pq.poll();
			for (int i = 0; i < party1.number; i++) {
				System.out.print(" " + party1.letter + party2.letter);
			}

			System.out.println();
		}

		sc.close();
	}
}

class Party {
	char letter;
	int number;

	Party(char letter, int number) {
		this.letter = letter;
		this.number = number;
	}
}