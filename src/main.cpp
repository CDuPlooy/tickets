/*
Connor Armand Du Plooy
u16169532
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include "tickets_includes.h"
#define VER "2.1"
#define MAGIC_NUMBER 1
using namespace std;

char MainMenu(){
      char acceptableChars [7] = { 'a' , 'b', 'c' , 'd', 'e' ,'f','g' };
      char a = 0x0;
      cout << "Ticktes " VER << endl;
      cout <<"Main menu: " << endl;
      cout << "a.) Create an auditorium" << endl;
      cout << "b.) List auditoriums" << endl;
      cout << "c.) Save an auditorium" << endl;
      cout << "d.) Load an auditorium" << endl;
      cout << "e.) Booking subsystem" << endl;        //TODO: Enable undo functionality ; Setup working backup
      cout << "f.) Summary " << endl;
      cout << "g.) Exit" << endl;

      bool canExit = false;
      while( MAGIC_NUMBER ){
      cout << GREEN ">>> " RESET;
      a = getchar();

      for(unsigned short i = 0 ; i < 7 ; i++)
            if(a == acceptableChars[i])
                  canExit = true;
      if(canExit)
            break;
      }
      system("clear");
      return a;
}

char audType(){
      char acceptableChars [2] = {'d' ,'f' };
      char a = 0x0;
      cout << "d.) Dynamic" << endl;
      cout << "f.) Fixed" << endl;


      bool canExit = false;
      while( MAGIC_NUMBER ){
      cout << GREEN ">>> " RESET;               //This might seem like an error but it's not , the compiler will optimize it. Linux kernel modules use the same trick.
      a = getchar();

      for(unsigned short i = 0 ; i < 2 ; i++)
            if(a == acceptableChars[i])
                  canExit = true;
      if(canExit)
            break;
      }
      system("clear");
      return a;
}

bool checkMinorOnly(Group group){
      for(size_t i = 0 ; i < group.getSize() ; i++ )
            if( group.at(i)->getId() != "Minor" )
                  return false;
      return true;
}

void bookings(Auditorium *auditorium){
      cout << "Enter names <s to stop>" << endl;
      Group group;
      std::string name = "abc";
      while(name != "s"){
            cout << GREEN ">>>" BLUE ">>> " RESET << endl;
            cin >> name;
            if(name != "s"){
                  Person *person;
                  cout << "What are you <p>ensioner , <a>dult or <m>inor" << endl;
                  cout << GREEN ">>>" BLUE ">>>" RED ">>> " RESET << endl;
                  char type = 'a';
                  cin >> type;
                  if(type == 'a')
                        person = new Adult();
                  else if(type == 'p')
                        person = new Pensioner();
                  else
                        person = new Minor();

                  person->setName(name);

                  group.push_back(person);
                  name = "abc";
            }
      }
      if(checkMinorOnly(group)){
            for(size_t i = 0 ; i < group.getSize() ; i++)
                  delete group.at(i);
            cout << RED "Minors cannot book alone!" << RESET << endl;
            return;
      }

      cout << "What strategy would you like to use ? " << endl;
      cout <<" 1.) Bad sight" << endl;
      cout <<" 2.) Best fit" << endl;
      cout <<" 3.) Best view" << endl;

      short bookType = BOOK_BEST_FIT;
      short temp;
      cin >> temp;
      if(temp == 1)
            bookType = BOOK_BAD_SIGHT;
      else if(temp == 2)
            bookType = BOOK_BEST_FIT;

      auditorium->bookStrat(&group , bookType);
      auditorium->print(cout);
}

int main(){
      char choice = 0x0;
      AuditoriumList audList;


      while(choice != 'e'){
            choice = MainMenu();
            switch (choice) {
                  case('a') :{
                        char audChoice = audType();
                        Auditorium *auditorium;
                        if( audChoice == 'd')
                              auditorium  = new DynamicAuditorium(5,5); //TODO: Prompt for values
                        else
                              auditorium = new FixedAuditorium(5,5);
                        cout << "Enter a name for the auditorium" << endl;
                        cout << GREEN ">>> " RESET;
                        string name;
                        cin >> name;
                        auditorium->setName(name);
                        auditorium->print(cout);
                        auditorium->enableMemento(true);
                        audList.push_back(auditorium);
                        break;
                  }
                  case('b') :{
                        if( audList.getSize() == 0){
                              cout << RED "No auditoriums!" << RESET << endl;
                              break;
                        }

                        for( size_t i = 0 ; i < audList.getSize() ; i++)
                              cout << i+1 << ".) " << GREEN << audList.at(i)->getName() <<  RESET << endl;
                        break;
                  }
                  case('c') :{
                        if( audList.getSize() == 0){
                              cout << RED "No auditoriums!" << RESET << endl;
                              break;
                        }

                        for( size_t i = 0 ; i < audList.getSize() ; i++)
                              cout << i+1 << ".) " << GREEN << audList.at(i)->getName() <<  RESET << endl;
                        cout << GREEN ">>> " RESET;
                        unsigned short num = -1; //Once again a compiler trick
                        cin >> num;

                        if(num > audList.getSize() || num < 0){
                              cout << RED "Invalid option!" << RESET << endl;
                              break;
                        }
                        std::string filename;
                        cout << "Enter an auditorium name." << endl;
                        cout << GREEN ">>> " RESET;
                        cin >> filename;
                        filename.append(".aud");
                        num--;
                        audList.at(num)->dumpFile(filename);
                        cout << "File " GREEN << filename << RESET " saved!" << endl;

                        break;
                  }
                  case('d') :{
                        AuditoriumDeveloper audDev;
                        string filename;
                        cout << "Enter the name of the file to load." << endl;
                        cout << GREEN ">>> " RESET;
                        cin >> filename;
                        if(audDev.loadFromFile(filename)){
                              audDev.getAuditorium()->enableMemento(true);

                              audList.push_back(audDev.getAuditorium());
                              string audName;
                              for( size_t i = 0 ; i < filename.length() ; i++ )
                                    if(filename[i] != '.')
                                          audName.push_back(filename[i]);
                                    else
                                          break;
                              audList.at(audList.getSize()-1)->setName(audName);
                              audList.at(audList.getSize()-1)->print(cout);
                        }
                        else{
                              cout << RED "Loading " << filename << RESET " failed!" << endl;
                        }


                        break;

                  }
                  case('e') :{
                        if( audList.getSize() == 0){
                              cout << RED "No auditoriums!" << RESET << endl;
                              choice = 0x0;
                              break;
                        }
                        cout << "Pick an auditorium to make a booking" << endl;
                        for( size_t i = 0 ; i < audList.getSize() ; i++)
                              cout << i+1 << ".) " << GREEN << audList.at(i)->getName() <<  RESET << endl;
                        cout << GREEN ">>> " RESET;
                        unsigned short num = -1; //Once again a compiler trick
                        cin >> num;
                        num--;
                        if(num > audList.getSize() || num < 0){
                              cout << RED "Invalid option!" << RESET << endl;
                              choice = 0x0;
                              break;
                        }
                        //Transfer execution flow to a temporary subsystem , the example CLI is getting messy.
                        bookings(audList.at(num));
                        choice = 0x0;
                        break;

                  }
                  case('f') :{
                        if( audList.getSize() == 0){
                              cout << RED "No auditoriums!" << RESET << endl;
                              choice = 0x0;
                              break;
                        }

                              for( size_t i = 0 ; i < audList.getSize() ; i++){
                                    Summary summary(audList.at(i));
                                    summary.print(cout);
                              }

                        break;
                  }
                  case('g'):{
                         for( size_t i = 0 ; i < audList.getSize() ; i++){
                              delete audList.at(i);
                         }
                        cout << GREEN "Thank" BLUE " you" RED " for" GREEN " using" BLUE " tickets" RED " !"  RESET << endl;
                        return 0;
                  }
            }
      }
      return 0;
}
