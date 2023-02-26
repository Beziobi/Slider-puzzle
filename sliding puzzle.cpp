#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
// for shuffle 
void swap (char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void randomize (char arr[], int n)
{ 
    srand (time(NULL));   
    for (int i = n - 1; i > 0; i--)
    {
      
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// node for slide 
struct slide 
{
	char value;
	int count;
	slide * next;
	slide * prev;
	
} *head , *temp , *temp_1 , *temp_2 , *temp_3 , *temp_4 , *temp_5;

int main()
{
	bool play_aa = true;
	
while (play_aa == true)
{

	cout << "3 by 3 sliding puzzle " <<endl;
	cout << "\n" << endl;
	// array 
	char arr[] = {'1', '2', '3', '4', '5', '6', '7', '8', '_'};
	int n = 9;
	randomize (arr, n);
	char play_a;
	// store it in the slide node 
	slide * s = new slide;
	head = s ;
	s -> value = arr[0];
	s -> count = 1;
	s -> next = NULL;
	s -> prev = NULL;
	
	temp = head;
	for (int i = 1 ; i <= 8 ; i ++)
		{
			while (temp -> next != NULL)
			{
				temp = temp -> next ;
			}
			slide * s = new slide ;
			temp -> next = s ; 
			s -> value = arr[i];
			s -> count = (temp -> count + 1);
			s -> next = NULL;
			s -> prev = temp;			
		}

		bool sort = false; 
		int check = 0;	
		while (sort == false )
		{
			// sliding puzzle 
			temp_4 = head;
			cout << "  -----------" <<endl;
			for (int i = 0 ; i < 3 ; i++)
			{
				cout << " | " << temp_4-> value ;
				temp_4= temp_4-> next;
			}
			cout << " | " <<endl;
			cout << " |===|===|===|" <<endl;
			for (int i = 0 ; i < 3 ; i++)
			{
				cout << " | " << temp_4 -> value ;
				temp_4= temp_4-> next;
			}
			cout << " | " <<endl;
			cout << " |===|===|===|" <<endl;
			for (int i = 0 ; i < 3 ; i++)
			{
				cout << " | " << temp_4 -> value  ;
				temp_4= temp_4-> next;
			}
			cout << " | " << endl;
			cout << "  -----------" <<endl;
			// sliding puzzle display ends 
//--------------------------------------
	
			// move 	
			char button;
			button = _getch();

			// for count 
			int c1;

			// for W and w ^
			if (button == 'W' || button == 'w')
			{
				temp_2 = head;
				while (temp_2 -> value != '_')
				{
					temp_2 = temp_2 -> next;
				}
				c1 = temp_2 -> count - 3 ;
				temp_3 = temp_2;
				if (temp_2 -> count == 1 || temp_2 -> count == 2 || temp_2 -> count == 3 )
				{
			
				}
				else 
				{
				while (temp_2 -> count != c1)
				{
					temp_2 = temp_2 -> prev;
				}
				temp_3 -> value = temp_2 -> value ;
				temp_2 -> value = '_';
				}	
			}

			// for S and s 
			else if (button == 'S' || button == 's')
			{
				temp_2 = head ;
				while (temp_2 -> value != '_')
				{
					temp_2 = temp_2 -> next ;
		
				} 
				c1 = temp_2 -> count + 3;
				temp_3 = temp_2;
				if (temp_2 -> count == 7 || temp_2 -> count == 8 || temp_2 -> count == 9)
				{
		
				}
				else 
				{
					while (temp_2 -> count != c1)
					{
						temp_2 = temp_2 -> next;
					}
					temp_3 -> value = temp_2 -> value;
					temp_2 -> value = '_';
				}
			}	

			// for A and a <-

			else if (button == 'A' || button == 'a')
			{
				temp_2 = head ;
				while (temp_2 -> value != '_')
				{
					temp_2 = temp_2 -> next ;
		
				} 
				c1 = temp_2 -> count - 1;
				temp_3 = temp_2;
				if (temp_2 -> count == 1 || temp_2 -> count == 4 || temp_2 -> count == 7)
				{
		
				}
				else 
				{
					while (temp_2 -> count != c1)
					{
						temp_2 = temp_2 -> prev;
					}
					temp_3 -> value = temp_2 -> value;
					temp_2 -> value = '_';
				}
			}	

			// for D and d ->
			else if (button == 'D' ||button == 'd')
			{
				temp_2 = head ;
				while (temp_2 -> value != '_')
				{
					temp_2 = temp_2 -> next ;
		
				} 
				c1 = temp_2 -> count + 1;
				temp_3 = temp_2;
				if (temp_2 -> count == 3 || temp_2 -> count == 6 || temp_2 -> count == 9)
				{
		
				}
				else 
				{
					while (temp_2 -> count != c1)
					{
						temp_2 = temp_2 -> next;
					}
					temp_3 -> value = temp_2 -> value;
					temp_2 -> value = '_';
				}
			}
			// for sort 	

			temp_5 = head;	
			check = 0;
			for (int i = 0 ; i < 8 ; i++)
			{
		
				check = check * 10;
				check += (temp_5 -> value - 48 );
				temp_5 = temp_5 -> next; 	
			}

			// check 		
			if (check == 12345678)
			{
				cout << "winner" << endl;
				cout << " " << endl;
				cout << " " << endl;
				
				cout << "To play again press Y to exit press N" << endl;
				
				cin >> play_a;
				if (play_a == 'y' || play_a == 'Y')
				{
					sort == true;
					play_aa = true;
				}
				
				else if (play_a == 'n' || play_a == 'N')
				{
					sort = true;
					play_aa = false;
				}
				else
				{
					cout << "Invalid input" << endl;
				}	
			}
			else 
			{
				sort = false;
			}
			
			bool play_a = false;
			
		

			system("cls");	
			cout << check << endl;

			}	

}
	return 0;
}
