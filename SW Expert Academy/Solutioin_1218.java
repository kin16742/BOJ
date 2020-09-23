package ssafy;

import java.util.Scanner;
import java.util.Stack;

public class Solutioin_1218 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		for (int test_case = 1; test_case <= 10; test_case++) {
			int n = sc.nextInt();
			String str = sc.next();
			boolean res = true;
			Stack<Character> s1 = new Stack();
			Stack<Character> s2 = new Stack();
			Stack<Character> s3 = new Stack();
			Stack<Character> s4 = new Stack();
			for (int i = 0; i < n; i++) {
				char c = str.charAt(i);
				switch (c) {
				case '<':
					s1.push(c);
					break;
				case '(':
					s2.push(c);
					break;
				case '[':
					s3.push(c);
					break;
				case '{':
					s4.push(c);
					break;
				case '>':
					if (s1.empty())
						res = false;
					else
						s1.pop();
					break;
				case ')':
					if (s2.empty())
						res = false;
					else
						s2.pop();
					break;
				case ']':
					if (s3.empty())
						res = false;
					else
						s3.pop();
					break;
				case '}':
					if (s4.empty())
						res = false;
					else
						s4.pop();
				}
				if (!res)
					break;
			}
			
			if (!s1.empty() || !s2.empty() || !s3.empty() || !s4.empty())
				res = false;
			
			System.out.print("#" + test_case + " ");
			if (res)
				System.out.print("1\n");
			else
				System.out.print("0\n");
		}
	}
}
