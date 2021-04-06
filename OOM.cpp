#define _CRTDBG_MAP_ALLOC //Loads in debug library
#include <iostream> // used to read or write to the standard input/output streams 
#include <string> // needed to use the string data type
#include <conio.h> // This header declares several useful library functions for performing "console input and output" from a program.
#include <typeinfo>
#include <crtdbg.h>//used for debugging 



using namespace std;
int flagged = 0;
int flagged2 = 0;
int currentRange;
int temp; // variable to store temperary data
bool exists = false;
	
    // templates start here // 
	template <typename TKey, typename TValue>
	class Map
	{
		private:
			struct Pair
			{
				TKey Key;
				TValue Value;
			};
			
			int mapMaximum;
			int mapRange;
			Pair* MapPair;
	
		public:
			Map();
			void Set(TKey key, TValue value); 
			void Remove(TKey key); 
			TValue Get(TKey key);
			void FindKey(TKey key);
			void FindValue(TValue value);
			void sortByDesc();
			void sortByAsc();
			int getSize();
			void setSize(int MapRange,int currentRange);
			void printMap();
			void printSingleElement(TKey key);
			void sortByDescValue();
			void sortByAscValue();
			bool checkElementExists(TKey key);
	};
	template <typename TKey,typename TValue>
	Map<TKey, TValue>::Map()
		{
			mapMaximum = 0; //capacity
			mapRange = 0; //size
		}
	//SET TEMPLATE//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::Set(TKey key, TValue value) {   
	
		if(this->checkElementExists(key) == false){
		 	for(int x= 0; x < mapRange; x++){
				if (MapPair[x].Key==key){
					MapPair[x].Value=value;
				}
			}
			if (mapRange == mapMaximum){
				mapMaximum++;
				Pair* tempPair = new Pair[mapMaximum];
					
				for (int x=0;x <mapRange;x++){
					tempPair[x]=MapPair[x];
				}
						
				MapPair =new Pair[mapMaximum];
				MapPair = tempPair;
			}
			
			//insert new pair
			MapPair[mapRange].Key=key;
			MapPair[mapRange].Value=value;
			mapRange++;
		}
		else{
			cout <<"This key already exists";
			return;
		}
	}	
	// REMOVE TEMPLATE//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::Remove(TKey key){
		
		Pair* tempPair = new Pair[mapRange];
		
		int j = 0; // j is the new counter
		for(int x = 0; x < mapRange; x++){
			if(MapPair[x].Key != key){			
				tempPair[j] = MapPair[x];
				j++;
			}	
		}		
		mapRange = j;		
		MapPair = new Pair[mapRange]; // j is the new map range
		MapPair = tempPair;	
		
	}
	//SEARCH MAP USING KEYWORDS//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::FindKey(const TKey key){	
			this->printSingleElement(key);
	}				
	// SEARCH MAP USING VALUES //
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::FindValue(const TValue value){
		
		for(int x = 0; x < mapRange; x++){
			if(MapPair[x].Value == value){			
				this->printSingleElement(MapPair[x].Key);
			}	
		}		
	}		
	//SORT MAP DESC ORDER BY KEY//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::sortByDesc(){
		
		Pair* SortPair = new Pair[mapRange];
		
		for(int x = 0; x < mapRange; x++){
			for(int y =0; y < mapRange - 1; y++)
			{
				if(MapPair[y+1].Key > MapPair[y].Key)
				{
					// temporary container to hold the map pair to swap
					SortPair[y] = MapPair[y+1];
					MapPair[y+1] = MapPair[y];
					MapPair[y] = SortPair[y];
					y++;
				}
				Pair* MapPair = MapPair;
			}
}
}
	//SORT MAP  DESC ORDER BY VALUE//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::sortByDescValue(){
		
		Pair* SortPair = new Pair[mapRange];
		for(int x = 0; x < mapRange; x++){
			for(int y =0; y < mapRange - 1; y++)
			{
				if(MapPair[y+1].Value > MapPair[y].Value)
				{
					// temporary container to hold the map pair to swap
					SortPair[y] = MapPair[y+1];
					MapPair[y+1] = MapPair[y];
					MapPair[y] = SortPair[y];
					y++;
				}
				Pair* MapPair = MapPair;
			}
}
}
	//SORT MAP ASCENDING ORDER BY KEY
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::sortByAsc(){
		
		Pair* SortPair = new Pair[mapRange];
		
		for(int x = 0; x < mapRange; x++){
			for(int y =0; y < mapRange - 1; y++)
			{
				if(MapPair[y+1].Key < MapPair[y].Key)
				{
					// temporary container to hold the map pair to swap
					SortPair[y] = MapPair[y+1];
					MapPair[y+1] = MapPair[y];
					MapPair[y] = SortPair[y];
					y++;
				}
				Pair* MapPair = MapPair;
			}
}
}
	//SORT MAP ASCENDING ORDER BY VALUE
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::sortByAscValue(){
		
		Pair* SortPair = new Pair[mapRange];
		
		for(int x = 0; x < mapRange; x++){
			for(int y =0; y < mapRange - 1; y++)
			{
				if(MapPair[y+1].Value < MapPair[y].Value)
				{
					// temporary container to hold the map pair to swap
					SortPair[y] = MapPair[y+1];
					MapPair[y+1] = MapPair[y];
					MapPair[y] = SortPair[y];
					y++;
				}
				Pair* MapPair = MapPair;
			}
}
}
	//GET SIZE//
	template <typename TKey, typename TValue>
	int Map<TKey, TValue>::getSize(){
		//mapRange = mapRange + 1;
		return mapRange;
	}
	//SET SIZE//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::setSize(int newRange,int currentRange){
		if (newRange >= currentRange){
			Pair* tempPair = new Pair[newRange];
				
				for (int x=0;x <mapRange;x++){
					tempPair[x]=MapPair[x];
				}
				MapPair =new Pair[newRange];
				MapPair = tempPair;
				mapRange= newRange;
		}
	}
	//PRINT MAP //
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::printMap(){

		for(int x = 0; x < mapRange; x++){
			cout<< MapPair[x].Key << "|" << MapPair[x].Value;
			cout << "\n";
		}
	}
	//PRINT SINGLE ELEMENT//
	template <typename TKey, typename TValue>
	void Map<TKey, TValue>::printSingleElement(TKey key){
	int flag = 0;
		for(int x = 0; x < mapRange; x++){
			if(MapPair[x].Key == key){
				cout<< MapPair[x].Key << "|" << MapPair[x].Value;
				cout << "\n";
			}
			else{
				flag++;
			}	
		}
		
		if(flag < (mapRange - 1)){
			cout <<"Item can't be found";
			flag = 0;
		}
	}
	//PRINT SINGLE ELEMENT//
	template <typename TKey, typename TValue>
	
	bool Map<TKey, TValue>::checkElementExists(TKey key){

		int flag = 0;
		for(int x = 0; x < mapRange; x++){
			if(MapPair[x].Key == key){
				return true;
			}
		}
		return false;
	}

	int main(){
		
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);// if anything goes wrong will tell us in the output
		int answer; // used to store an input value from user on main menu
		
	
		//all maps below have predetermined keys and values for testing
		//train seat map setup//
		Map <string, int>* trainseating = new Map<string, int>(); //creates a new map called trainsteating
		trainseating->Set("Marc", 650);//adds key and value to the new map
		trainseating->Set("Andrew", 100);//adds key and value to the new map
		trainseating->Set("Isaac", 204);//adds key and value to the new map
		trainseating->Set("Jamie", 384);//adds key and value to the new map
		trainseating->Set("Sarah", 494);//adds key and value to the new map
		
		//gig ticket map setup//
		Map<char, int>* gigticket= new Map<char, int>(); // creates a new map called gigticket
		gigticket->Set('a',14);//adds key and value to the new map
		gigticket->Set('g',3);//adds key and value to the new map
		gigticket->Set('h',34);//adds key and value to the new map
		gigticket->Set('o',38);//adds key and value to the new map
		
		//exchangeRate map setup//
		Map<float, int>*  exchangeRate= new Map<float, int>();// creates a new map called exchangeRate
		exchangeRate->Set(14.50,15);//adds key and value to the new map
		exchangeRate->Set(13.40,10);//adds key and value to the new map
		exchangeRate->Set(15.00,20);//adds key and value to the new map
		exchangeRate->Set(20.00,25);//adds key and value to the new map
	
		//roundingNumbers map setup//
		Map<double, int>*  roundingNumbers= new Map<double, int>(); // creates a new map called roundingNumbers
		roundingNumbers->Set(10.10,15);//adds key and value to the new map
		roundingNumbers->Set(20.70,20);//adds key and value to the new map
		roundingNumbers->Set(23.60,24);//adds key and value to the new map
		roundingNumbers->Set(25.65,26);//adds key and value to the new map
		roundingNumbers->Set(20.20,20);//adds key and value to the new map
		roundingNumbers->Set(3.60,4);//adds key and value to the new map
		roundingNumbers->Set(2.3,70);//adds key and value to the new map
		
		//quesrionnaireReview map setup//
		Map<float, char>*  questionnaireReview = new Map<float, char>(); // creates a new map called questionnaireReview
		questionnaireReview->Set(10.40,'a');//adds key and value to the new map
		questionnaireReview->Set(10.50,'b');//adds key and value to the new map
		questionnaireReview->Set(15.00,'c');//adds key and value to the new map
		questionnaireReview->Set(107.50,'d');//adds key and value to the new map
		
		
		//multichoiceResults map setup//
		Map<double, char>*  multichoiceResults= new Map<double, char>(); // creates a new map called multichoiceResults
		multichoiceResults->Set(10.60,'q');//adds key and value to the new map
		multichoiceResults->Set(16.80,'w');//adds key and value to the new map
		multichoiceResults->Set(12.60,'s');//adds key and value to the new map
		multichoiceResults->Set(14.40,'t');//adds key and value to the new map
		
		//characterTable map setup//
		Map<string, char>*  characterTable= new Map<string, char>();// creates a new map called characterTable
		characterTable->Set("letterone",'a');//adds key and value to the new map
		characterTable->Set("lettertwo",'a');//adds key and value to the new map
		characterTable->Set("letterthree",'a');//adds key and value to the new map
		characterTable->Set("letterfour",'a');//adds key and value to the new map
		characterTable->Set("letterfive",'a');//adds key and value to the new map
		
		//shoppingCart map setup//
		Map<float, string>*  shoppingCart= new Map<float, string>();// creates a new map called shoppingCart
		shoppingCart->Set(12.00,"White tshirt M");//adds key and value to the new map
		shoppingCart->Set(13.00,"Blue Joggers 32R");//adds key and value to the new map
		shoppingCart->Set(15.00,"Purple Hoodie M");//adds key and value to the new map
		shoppingCart->Set(75.00, "Levi Jeans 32R");//adds key and value to the new map
		
		//weightconversion map setup//
		Map<double, float>*  weightConversion= new Map<double, float>();// creates a new map called weightConversion
		weightConversion->Set(10.00,15.00);//adds key and value to the new map
		weightConversion->Set(15.00,10.00);//adds key and value to the new map
		weightConversion->Set(40.00,45.00);//adds key and value to the new map
		weightConversion->Set(45.00,40.00);//adds key and value to the new map
		
		//studentScore map setup //
		Map<string, double>* studentScore = new Map<string, double>();// creates a new map called studentScore
		studentScore->Set("Andrew", 70.00); //adds key and value to the new map
		studentScore->Set("Sarah", 85.00);//adds key and value to the new map
		studentScore->Set("Trevor", 45.70);//adds key and value to the new map
		studentScore->Set("Sally", 65.29);//adds key and value to the new map
		studentScore->Set("Gemma", 47.00);//adds key and value to the new map
		studentScore->Set("Ben", 49.70);//adds key and value to the new map
		studentScore->Set("Michael", 47.00);//adds key and value to the new map
		
	do {
		cout << "Pick a choice from the list: " << endl; // prints out what the user can do

	    cout << "1.  Adding a new trainticket to the map (string,int)\n"; // option 1 adding to a map
	    cout << "2.  Printing the student results map (string, double)\n";// option 1 printing  a map
	    cout << "3.  Remove an element from shopping cart (float, string)\n";// remove data from a map
	    cout << "4.  Search a weight conversion map by key (double, float)\n";// search map by key
	    cout << "5.  Search a multichoice map by value(double, char)\n";// search map by value
	    cout << "6.  Get and Set the size of the questionnaireReview map (float, char)\n"; // get the size and set the size of a map
	    cout << "7.  Organise a gig ticket table in descending order by key(chat, int)\n"; // organise map by key in descending order
	    cout << "8.  Organise a exchange rate map in descending order by value (float, int)\n";// organise map by value in descending order
	    cout << "9.  Organise a rounding numbers map in ascending order by key (double,int)\n";// organise map by key in ascending order
	    cout << "10. Organise a character map in ascending order by value (string, char)\n";// organise map by value in ascending order
		cin >> answer;
	    
	    switch(answer){
	    	case 1:
	    		system("CLS"); // clears the screen 
	    		cout <<"This is the current train seating map:\n\n"; // outputs for the user
	    		trainseating->printMap(); //runs the printMap function and outputs the map on the screen
	    		cout <<"\n\nNow a new seat will be added with the values James and 675\n\n"; //outputs information for user
	    		trainseating->Set("James",675);//adds new data into the map
	    		trainseating->printMap();//prints new map with data added to it
	    		cout <<"\n\n";
	    		cout <<"\n Now James and 675 will be added again.\n";//outputs information again
	    		trainseating->Set("James",675);//trys to set the same inforamtion to check key validation is working
	    		cout <<"\n";
	    		trainseating->printMap();//prints new map
	    		cout <<"\nJames hasns't been added twice into the map"; //output confirms that key validation is working
	    		break;
	    	case 2:
	    		system("CLS");
	    		cout <<"This is the current student results map:\n\n";
	    		cout <<"Name | Score \n\n";
	    		studentScore->printMap();
	    		break;
	    	case 3:
	    		system("CLS");
	    		cout <<"These are the current items in a shopping cart:\n\n";
	    		cout <<"\n" << char(156)<<"| Item Description\n";
	    		shoppingCart->printMap();
	    		cout <<"\n";
	    		cout <<"The levi jeans will be removed from the shopping cart:\n\n";
	    		shoppingCart->Remove(75.00);//removes data using the key from map
	    		cout <<"\n";
	    		shoppingCart->printMap(); //prints new map showing item has been deleted
	    		break;
	    	case 4:
	    		system("CLS");
	    		cout <<"This is the current weight conversion map:\n\n";
	    		cout <<"pounds | kilograms\n";
	    		weightConversion->printMap();
	    		cout <"\n\n";
	    		cout <<"We will now search the map using the key value (40.00)\n";
	    		weightConversion->FindKey(40.00); // searches map for key and outputs it onto screen
	    		cout <"\n\n";
	    		cout <<"We will now search the map using the key  (10.00)\n";
	    		weightConversion->FindKey(10.00);// searches map for another key and outputs it onto screen
	    		cout <"\n\n";
	    		cout <<"We will now search the map using the key (45.00)\n";
	    		weightConversion->FindKey(45.00);// searches map for a third value and outputs it onto screen
	    		break;
	    	case 5:
	    		system("CLS");
	    		cout <<"This is the current multichoice Results  map:\n\n";
	    		cout <<"correct percentage | question\n";
	    		multichoiceResults->printMap();
	    		cout <"\n";
	    		cout <<"We will now search the map using the value (t)\n";
	    		multichoiceResults->FindValue('t');//searches map for value and outputs it onto screen
	    		cout <"\n";
	    		cout <<"We will now search the map using the value (w)\n";// searches map for another value and outputs it onto screen
	    		multichoiceResults->FindValue('w');
	    		cout <"\n";
	    		cout <<"We will now search the map using the value (s)\n";// searches map for a third value and outputs it onto screen
	    		multichoiceResults->FindValue('s');
	    		break;
	    	case 6:
	    		system("CLS");
	    		cout << "the current size of the questionnaireReview map is:\n";
	    		cout << questionnaireReview->getSize(); //gets the size of the current map
	    		cout <<"\n";
	    		cout <<"\nWe will now set the size of the map to '10'\n";
	    		questionnaireReview->setSize(10,questionnaireReview->getSize()); // sets the size of the map to 10
	    		cout <<"\n";
	    		cout << "the new size of the questionnaireReview map is:\n";
	    		cout << questionnaireReview->getSize();//prints out the new mapsize onto screen
	    		break;
	    	case 7:
	    		system("CLS");
	    		cout <<"This is the current gig seating map:\n\n";
	    		cout <<"Row | Seatnumber \n";
	    		gigticket->printMap();
	    		cout <<"\n";
	    		cout <<"This is the gig seating map in descending order by key:\n";
	    		gigticket->sortByDesc();// sorts the map by key in Desc order
	    		gigticket->printMap();
	    		break;
	    	case 8:
	    		system("CLS");
	    		cout <<"This is the current exchange rate map:\n\n";
	    		cout << "Euro | Pound";
	    		exchangeRate->printMap();
	    		cout <<"\n";
	    		cout <<"This is the exchange rate map in descending order by value:\n";
	    		exchangeRate->sortByDescValue();// sorts the map by value in Desc order
	    		exchangeRate->printMap();
	    		break;
	    	case 9:
	    		system("CLS");
	    		cout <<"This is the current rounding numbers map:\n\n";
	    		cout << "Decimal | Rounded \n";
	    		roundingNumbers->printMap();
	    		cout <<"\n";
	    		cout <<"This is the rounding numbers map in ascending order by key:\n";
	    		roundingNumbers->sortByAsc();// sorts the map by key in Asc order
	    		roundingNumbers->printMap();
	    		break;
	    	case 10:
	    		system("CLS");
	    		cout <<"This is the current rounding numbers map:\n\n";
	    		cout << "Decimal | Rounded \n";
	    		roundingNumbers->printMap();
	    		cout <<"\n";
	    		cout <<"This is the rounding numbers map in ascending order by value:\n";
	    		roundingNumbers->sortByAscValue();// sorts the map by value in Asc order
	    		roundingNumbers->printMap();
	    		break;
	    	default:
				cout << "Bad choice! Please try again later.\n";
				system("CLS"); 
				
				}
	
	}while (answer < 1 || answer > 10);	
			
}
