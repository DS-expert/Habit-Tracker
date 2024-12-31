#include <iostream>
#include <string>
using namespace std;

const int MaxHabit = 5; // limit of vHabit
int totalHabit = 0; // how much habit in the list
string habits[MaxHabit]; // to store habits from user
int streaks[MaxHabit]; // To Count the streaks of user to done Habits
bool doneHabits[MaxHabit] = {false}; // Done Habits Count 
int deleted_habits = 0;

void createHabit(); // Prototype of Create Habit function
void removeHabit(); // Function of Remove Habit 
void analyzeHabit(); // Function of Analyze Habit 
void updateHabit(); // Function of Update Habit 
void displayMenu(); // Function of Display Menu


int main() // Main Body 
{
    cout << "\t\t-----Habit Tracker-------" << endl; // Welcome Text of The Program 

    cout << "Habit Tracker is the Program to Track habits of yours "; // Introduction Line
    cin.get(); // Pause for the user to press the Enter
    cout << "For Lazy People like you and me to don't Forget about What you Start. "; // Introduction Line
    cin.get();

    int choice; // Variable for Menu Choice 
    
    while(true) // Start Loop 
    
    {
        displayMenu(); // Call the display Menu 
        
        cout << "Enter your Choice: "; 
        cin >> choice; // Get the choice

        switch(choice) // Conidtional Statement by Switch 
        {

            case 1: createHabit(); break; // Call the Create Habit when you enter 1
            case 2: analyzeHabit(); break; // Call the Analyze Habit when you enter 2
            case 3: removeHabit(); break; // Call the Remove Habit when you enter 3
            case 4: updateHabit(); break; // Call the Update Habit when you enter 4
            case 5: cout << "Exiting The Program, Good BYE! " << endl; return 0; // Break the Program when you enter 5 {Not Working Perfectly}
            default: cout << "Invalid Operation! Sorry " << endl; break; // Else Case
    }
    
}

}

void displayMenu() // Function of Display Menu 
{
    cout << "\n\t-------Habit Tracker-------\n"; // Menu Display
    cout << "\n1. Create Habit " << endl;
    cout << "2. Analyze Habit " << endl;
    cout << "3. Remove Habit " << endl;
    cout << "4. Update Habit " << endl;
    cout << "5. Exit " << endl;
    cout << "-----------------------------------\n";
}

void createHabit() // Function of Create Habit 
{
    cout << "\t--------Create Habit----------" << endl; // Welcome Line 

    if (totalHabit == MaxHabit) // Check the Limit of Habit 
    {
        cout << "\nWarning! The Limit Reached!!! \n" << endl; // When the Limit Reached then Don't Continue the Process in Create Habit
        return; 
    }

    while (totalHabit < MaxHabit)
    {
    int add_in; 

    cout << "1. Add the Habit " << endl; // Option in Create Habit
    cout << "2. Return to Home Page......." << endl;
    cout << "--------------------" << endl;
    cout << "Enter your Choice: " ;
    cin >> add_in; 

    if (add_in == 1) // Conditional Statement of Choice of User 
    {
        
            int createhabit_choice; // User Choice After Adding the Habit. 
            cout << "\n----------------------" << endl;
            cout << "\nEnter New Habit: ";
            cin.ignore(); // Remove Buffer 
            getline(cin, habits[totalHabit]); // Input the Habit with Get line 
            totalHabit++; // Increment in total Habits to Count. 
            cout << "-------------------------" << endl;
    
    }

    else if(add_in == 2)
    {
        cout << "Returning to Home Page......" << endl;
        return;
    }

    else // Else Invalid input before the Adding the Habit. 
    {
        cout << "Sorry! Invalid Input " << endl;
    }

    }
    cout << "The Limit has been Reached!" << endl; // When loop Finish then Print this
}

void analyzeHabit() // Analyze the habit 
{

    if (totalHabit == 0) // Check the list is not Empty
    {
        cout << "\nFirst Create a Habit! Thank you " << endl;
        return;
    }
    while (true)
    {
        int choose_option_analyze;
        cout << "\t------Analyze Habit------" << endl; // Menu of Analyze habit Section
        cout << "1. Habits " << endl;
        cout << "2. Habit Analysis " << endl;
        cout << "3. Deleted Habits " << endl;
        cout << "4. Return to Home Page" << endl;
        cout<< "-------------------------------" << endl;
        cout << "Enter your Choice: " ;

        cin >> choose_option_analyze; // chose Option

        if (choose_option_analyze == 1) // press 1 scencorio
        {
            int iteration_habit = 0;
            cout << "\t------Habits--------" << endl;

            while (iteration_habit != totalHabit) // Loop will end if the iteration met with total Habits
            {
                cout << habits[iteration_habit] << endl; // Print List of Habit
                iteration_habit++; // Increment
            }

        }

        else if(choose_option_analyze == 2) // Press 2 Scenorio
        {
            cout << "\t-------Habit Analysis-------" << endl; // Habit Analysis Part After from Update Section 

            cout << "\n-----------------------------" << endl;
            cout << "\n\t Habit Status " << endl;
            for (int i = 0; i < totalHabit; i++)
            {
                cout << habits[i] << " : " << (doneHabits[i] ? "Done" : "not done")<<" : Streaks = "<<streaks[i] << endl;
            }
            cout << "-----------------------------" << endl;


        }

        else if (choose_option_analyze == 3)
        {
            cout << "\t--------Deleted Habits-------" << endl;
            cout << "\n------------------------------"<<endl;
            cout << "Deleted Habits is " << deleted_habits << endl;
            cout << "-------------------------------" << endl;

        }

        else if (choose_option_analyze == 4)
        {
            cout << "\nReturning to Home Page........" << endl;
            return; 
        }

        else
        {
            cout << "\nSorry Invaild Option! Try Again " << endl;
        }
    }
    
}

void removeHabit()
{
   
    
    if (totalHabit == 0)
    {
        cout << "\nFirst Create Habit! Thank you " << endl;
        return ;
    }
    
    while (true)
    {
        int choose_option_remove;
        cout << "\t\n--------Remove Habit---------" << endl;
        cout << "1. Remove Habit " << endl;
        cout << "2. Return to Home Page " << endl;
        cout << "---------------------------------" << endl;
        cout << "Enter your Choice: ";
        cin >> choose_option_remove; 

        
        if (choose_option_remove == 1)
        {
            cout << "\t------Habits to Remove----" << endl;

            int iteration_habit = 0;

            while (iteration_habit != totalHabit)
            {
                cout << iteration_habit+1 << ". " << habits[iteration_habit] << endl;
                iteration_habit++;
            }

            int index_remove;
            cout << "Enter your habit index to Remove " << endl;
            cin >> index_remove;
             
            if (index_remove > 0 && index_remove <= totalHabit)
            {
                string verification_bool;
                cout << "Are you Sure to Remove " << habits[index_remove-1] << "(yes / no)" << endl;
                cin >> verification_bool;

                for(char &c  : verification_bool){
            
                c = tolower(c);
                }

                if (verification_bool == "yes" )
                {
                    for (int i = index_remove-1; i < totalHabit; i++)
                    {
                        habits[i] = habits[i + 1];
                        totalHabit--; 
                        deleted_habits++;
                        cout << "Habit Succefully Removed! " << endl;
                    }

                    
                    
                }

                else if (verification_bool == "no" || verification_bool == "YES")
                {
                    cout << "Habit Removed Operation Canceled! " << endl;
                }

                else
                {
                    cout << "Invalid Response! Try Again " << endl;
                }

                
            }else{
                cout<<"\nInvalip Input!! Please try again.\n";
            }
            
        }

        else if(choose_option_remove == 2)
        {
            cout << "\nReturning to Home Page......" << endl;
            return ;
        }
    }

}

void updateHabit()
{
    cout << "\t-------Update Habit-----------" << endl;
    if (totalHabit == 0)
    {
        cout << "First Create Habit! Thank you " << endl;
        return; 
    }

    while (true)
    {
        int choose_option_update;

        cout << "\n1 Update Habits " << endl;
        cout << "2. Return to HomePage.... "<< endl;
        cout << "-------------------------------" << endl;
        cin >> choose_option_update; 

        if (choose_option_update == 1)
        {
            cout << "\n\t-------Update Habit-------" << endl;

            for(int i=0; i<totalHabit; i++)
            {
                cout << i+1 << ". " << habits[i] << endl;

            }

            int choose_index_update;
            cout << "-------------------------" << endl;
            cout << "Enter your Habit Index to Update "; 
            cin >> choose_index_update;
            if(doneHabits[choose_index_update-1] == true){
                cout<<habits[choose_index_update-1]<<" is marked as done."<<endl;
                
            }else{
           if (choose_index_update > 0 && choose_index_update <= totalHabit)
           {

            string selectedHabit = habits[choose_index_update-1];
            string verification_bool;
            cout << "Are you Done " << selectedHabit << " ? (yes / no) ";
            cin >> verification_bool;

            for(char &c  : verification_bool){
            
                c = tolower(c);
                }


            if (verification_bool == "yes")
            {
                doneHabits[choose_index_update-1] = true;
                cout << "\n----------------------------------" << endl;
                cout << "\nHabit " << selectedHabit << " marked as done " << endl;
                cout << "\n----------------------------------" << endl;
                streaks[choose_index_update-1] =+ 1;
            }

            else if (verification_bool == "no")
            {
                doneHabits[choose_index_update-1] = false;
                cout << "\n----------------------------"<<endl;
                cout << "Habit " << selectedHabit << " marked as not done " << endl;
                cout << "\n---------------------------------" << endl;
                streaks[choose_index_update-1] = 0;
                
            }

            else
            {
                cout << "Invalid Response " << endl;
            }


           }

           else
           {
            cout << "\nSorry! Invalid Response " << endl;
           }

            }
        
        }

        else if (choose_option_update == 2)

        {
            cout << "\nReturning HomePage....." << endl;
            return ;
        }


    }
}
