#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void netflix_genre(vector<string> shows, vector<string> genres){
  cout << "These are the different genres to the top 10 shows:" << endl;
  cout << endl;
  for (int i = 0; i < shows.size(); i++){
    cout << "\t" << shows.at(i) << "  /  " << genres.at(i) << endl;
    cout << endl;
  }
}

void netflix_scores(vector<string> shows, vector<double> scores){
  cout << "These are the IMDB scores to the top 10 shows:" << endl;
  cout << endl;
  for (int i = 0; i < shows.size(); i++){
    cout << "\t" << shows.at(i) << "  /  " << scores.at(i) << endl;
    cout << endl;
  }
}

void print_menu(){
  cout << "*************************************" << endl;
    cout << "Top 10 Best Netflix Shows!" << endl;
    cout << "g - Show Genre" << endl;
    cout << "s - Show IMDB Score" << endl;
    cout << "q - To Quit" << endl;
    cout << "*************************************" << endl;
    cout << endl;
    cout << "Please enter your choice: " << endl;
}

void initialize_data(vector<string>& shows, vector<string>& genres, vector<double>& scores){
  ifstream file;
  string temp_s;
  double temp_d;
  file.open("netflix.txt");
  if(file.is_open()){
    while (!file.eof()){
      file >> temp_s;
      shows.push_back(temp_s);
      file >> temp_s; 
      genres.push_back(temp_s);
      file >> temp_d;
      scores.push_back(temp_d);
    }
    file.close();
    cout << "Initialized " << shows.size() << "genres..." << endl;
  }
  else{
    cout << "Error while obtaining file" << endl;
  }
}

void save_data(vector<string> shows, vector<string> genres, vector<double> scores){
  ofstream fout;
  fout.open("saved_data.txt");
  if(fout.is_open()){
    for (int i = 0; i < shows.size(); i++){
      fout << shows.at(i) << ", " << genres.at(i) << ", " << scores.at(i) << endl;
     }
    fout.close();
  }
}    

int main(){
  char user_inputNet;
  
  vector<string>shows;
  vector<string>genres;
  vector<double>scores;

  initialize_data(shows, genres, scores);
  
  do{
    print_menu();
    cin >> user_inputNet;
    cout << endl;
    switch(user_inputNet){
      case 'g':
        netflix_genre(shows, genres); 
        break;
      case 's':
        netflix_scores(shows, scores);
        break;
      case 'q':
        cout << "Goodbye! Happy Holidays!" << endl;
        save_data(shows, genres, scores);
        break;
      default:
      cout << "Invalid option, please try again!" << endl;
    }
    
  }
    while (user_inputNet != 'q');



  return 0;
}