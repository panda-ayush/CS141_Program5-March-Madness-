/* main.cpp
  Program 5 March Madness Frenzy

   Author: Ayush Panda
   Date: 04/06/2022
   Class: CS 141, Spring 2022, UIC
   System: Windows using CLion

  Description:A C++ program that reads in data
  from NCAA Basketball Tournaments (aka March Madness)
  and then provides information regarding that data
*/
#include <algorithm> //find function
#include <cassert>   //header file
#include <cctype>    //changing letters
#include <fstream>   // for file stream
#include <iostream>  //cout
#include <sstream>   //for stream object
#include <string>    // for strings
#include <vector>    // for vectors
using namespace std;

class brackets { //class for program

private: //private vector variables to seperate data from csv file
  vector<string> region;
  vector<string> rank1;
  vector<string> team1;
  vector<string> score1;
  vector<string> rank2;
  vector<string> team2;
  vector<string> score2;
  vector<string> winner;
  vector<string> round;
  vector<string> gameNumber;

public:
  void setterRegion(string Region) { region.push_back(Region); } //setter method for region vector

  const vector<string> &getterRegion() const { return region; } //getter method for region vector

  void setterRank1(string Rank1) { rank1.push_back(Rank1); } //setter method for rank 1 vector

  const vector<string> &getterRank1() const { return rank1; } //getter method for rank 1 vector 

  void setterTeam1(string Team1) { team1.push_back(Team1); } //setter method for team 1 vector

  const vector<string> &getterTeam1() const { return team1; } //getter method for team 1 vector 

  void setterScore1(string Score1) { score1.push_back(Score1); } //setter method for score 1 vector

  const vector<string> &getterScore1() const { return score1; } //getter method for score 1 vector

  void setterRank2(string Rank2) { rank2.push_back(Rank2); } //setter method for rank 2 vector

  const vector<string> &getterRank2() const { return rank2; } //getter method for rank 2 vector

  void setterTeam2(string Team2) { team2.push_back(Team2); } // setter method for team 2

  const vector<string> &getterTeam2() const { return team2; } // getter method for team 2 vector

  void setterScore2(string Score2) { score2.push_back(Score2); } //setter method for score 2 vector

  const vector<string> &getterScore2() const { return score2; } //getter method for score 2 vector

  void setterWinner(string Winner) { winner.push_back(Winner); } //setter method for winner vector

  const vector<string> &getterWinner() const { return winner; } //getter method for winner vector

  void setterRound(string Round) { round.push_back(Round); } //setter method for round vector

  const vector<string> &getterRound() const { return round; } //getter method for round vector

  void setterGameNumber(string GameNumber) { gameNumber.push_back(GameNumber); } //setter method for game number

  const vector<string> &getterGameNumber() const { return gameNumber; } 
//getter method for game number
};

//output instructions for program
void displayInstruction() {
  cout << "Program 5: March Madness Frenzy" << endl;
  cout << "CS 141, Spring 2022, UIC" << endl << endl;

  cout << "This program reads in data from NCAA Basketball Tournaments (aka "
          "March Madness). It provides overall information regarding the data, "
          "allows you to see the path taken to the championship, uses rankings "
          "of teams to determine which region is expected to win at a given "
          "round and to find the best underdog team, and calculates point "
          "differences within the games. You can also compare the actual "
          "brackets to your own predictions!"
       << endl
       << endl;

  cout << "Enter the name of the file with the data for the NCAA tournament:"
       << endl;
}

// display menu options
void menuOption() {
  cout << "Select a menu option:" << endl;
  cout << "\t1. Display overall information about the data" << endl;
  cout << "\t2. Display the path of the winning team to the championship"
       << endl;
  cout << "\t3. Determine which region is expected to win the championship "
          "based on a given round"
       << endl;
  cout << "\t4. Identify the best underdog within a given round" << endl;
  cout << "\t5. Find the shoo-in and nail-biting games within a given round, "
          "or overall"
       << endl;
  cout << "\t6. Compare the actual brackets to your predicted brackets" << endl;
  cout << "\t7. Exit" << endl;
}

brackets data; //instance for original brackets
brackets prediction; //instance for prediction brackets

//file to read in original brackets
void readInFile(char fileName[], vector<string> &regionData, vector<string> &rank1Data, vector<string> &team1Data, vector<string> &score1Data, vector<string> &rank2Data, vector<string> &team2Data, vector<string> &score2Data, vector<string> &winningTeamData, vector<string> &roundNumberData, vector<string> &gameNumberData) {

  string input, region, rank1, team1, score1, rank2, team2, score2, winningTeam, roundNumber, gameNumber; //temp values to hold data from csv file

  ifstream inStream;
  inStream.open(fileName);

  assert(inStream.fail() == false);

  getline(inStream, input);

  while (getline(inStream, input)) {
    data.setterRegion(input.substr(0, input.find(","))); //checks for comma and passes in data from before the comma 

    regionData = data.getterRegion(); //gets data from class and passed into vector in main file
    region = input.substr(input.find(",") + 1); //gets next value after comma

    data.setterRank1(region.substr(0, region.find(","))); //checks for comma and passes in data from before the comma

    rank1Data = data.getterRank1();  //gets data from class and passed into vector in main file

    if (rank1Data.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterRank1("0");
    }

    rank1Data = data.getterRank1(); //gets data from class and passed into vector in main file

    team1 = region.substr(region.find(",") + 1); //gets next value after comma

    data.setterTeam1(team1.substr(0, team1.find(","))); //checks for comma and passes in data from before the comma

    team1Data = data.getterTeam1(); //gets data from class and passed into vector in main file
    score1 = team1.substr(team1.find(",") + 1); //gets next value after comma

    data.setterScore1(score1.substr(0, score1.find(","))); //checks for comma and passes in data from before the comma

    score1Data = data.getterScore1(); //gets data from class and passed into vector in main file

    if (score1Data.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterScore1("0");
    }

    score1Data = data.getterScore1(); //gets data from class and passed into vector in main file
    rank2 = score1.substr(score1.find(",") + 1); //gets next value after comma

    data.setterRank2(rank2.substr(0, rank2.find(","))); //checks for comma and passes in data from before the comma

    rank2Data = data.getterRank2(); //gets data from class and passed into vector in main file

    if (rank2Data.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterRank2("0");
    }

    rank2Data = data.getterRank2(); //gets data from class and passed into vector in main file
    team2 = rank2.substr(rank2.find(",") + 1); //gets next value after comma

    data.setterTeam2(team2.substr(0, team2.find(","))); //checks for comma and passes in data from before the comma

    team2Data = data.getterTeam2(); //gets data from class and passed into vector in main file
    score2 = team2.substr(team2.find(",") + 1); //gets next value after comma

    data.setterScore2(score2.substr(0, score2.find(","))); //checks for comma and passes in data from before the comma

    score2Data = data.getterScore2(); //gets data from class and passed into vector in main file

    if (score2Data.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterScore2("0");
    }

    score2Data = data.getterScore2(); //gets data from class and passed into vector in main file
    winningTeam = score2.substr(score2.find(",") + 1);  //gets next value after comma

    data.setterWinner(winningTeam.substr(0, winningTeam.find(","))); //checks for comma and passes in data from before the comma

    winningTeamData = data.getterWinner(); //gets data from class and passed into vector in main file
    roundNumber = winningTeam.substr(winningTeam.find(",") + 1); //gets next value after comma

    data.setterRound(roundNumber.substr(0, roundNumber.find(","))); //checks for comma and passes in data from before the comma

    roundNumberData = data.getterRound(); //gets data from class and passed into vector in main file

    if (roundNumberData.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterRound("0");
    }

    roundNumberData = data.getterRound(); //gets data from class and passed into vector in main file
    gameNumber = roundNumber.substr(roundNumber.find(",") + 1); //gets next value after comma

    data.setterGameNumber(gameNumber.substr(0, gameNumber.find(","))); //checks for comma and passes in data from before the comma

    gameNumberData = data.getterGameNumber(); //gets data from class and passed into vector in main file

    if (gameNumberData.empty() == true) { //checks if position is empty and if so passes in 0
      data.setterGameNumber("0");
    }

    gameNumberData = data.getterGameNumber(); //gets data from class and passed into vector in main file
  }
}

//funciton for predicitons bracket similar to previous function however passes values into vectors from predicitons bracket
void readInFile2(char fileName[], vector<string> &predictionRegion, vector<string> &predictionRank1, vector<string> &predictionTeam1, vector<string> &predictionScore1, vector<string> &predictionRank2, vector<string> &predictionTeam2, vector<string> &predictionScore2, vector<string> &predictionWinningTeam, vector<string> &predictionRoundNumber, vector<string> &predictionGameNumber) {

  string input, region, rank1, team1, score1, rank2, team2, score2, winningTeam, roundNumber, gameNumber;

  ifstream inStream;
  inStream.open(fileName);

  assert(inStream.fail() == false);

  getline(inStream, input);

  while (getline(inStream, input)) {
    prediction.setterRegion(input.substr(0, input.find(",")));

    predictionRegion = prediction.getterRegion();
    region = input.substr(input.find(",") + 1);

    prediction.setterRank1(region.substr(0, region.find(",")));

    predictionRank1 = prediction.getterRank1();

    if (predictionRank1.empty() == true) {
      prediction.setterRank1("0");
    }

    predictionRank1 = prediction.getterRank1();

    team1 = region.substr(region.find(",") + 1);

    prediction.setterTeam1(team1.substr(0, team1.find(",")));

    predictionTeam1 = prediction.getterTeam1();
    score1 = team1.substr(team1.find(",") + 1);

    prediction.setterScore1(score1.substr(0, score1.find(",")));

    predictionScore1 = prediction.getterScore1();

    if (predictionScore1.empty() == true) {
      prediction.setterScore1("0");
    }

    predictionScore1 = prediction.getterScore1();
    rank2 = score1.substr(score1.find(",") + 1);

    prediction.setterRank2(rank2.substr(0, rank2.find(",")));

    predictionRank2 = prediction.getterRank2();

    if (predictionRank2.empty() == true) {
      prediction.setterRank2("0");
    }

    predictionRank2 = prediction.getterRank2();
    team2 = rank2.substr(rank2.find(",") + 1);

    prediction.setterTeam2(team2.substr(0, team2.find(",")));

    predictionTeam2 = prediction.getterTeam2();
    score2 = team2.substr(team2.find(",") + 1);

    prediction.setterScore2(score2.substr(0, score2.find(",")));

    predictionScore2 = prediction.getterScore2();

    if (predictionScore2.empty() == true) {
      prediction.setterScore2("0");
    }

    predictionScore2 = prediction.getterScore2();
    winningTeam = score2.substr(score2.find(",") + 1);

    prediction.setterWinner(winningTeam.substr(0, winningTeam.find(",")));

    predictionWinningTeam = prediction.getterWinner();
    roundNumber = winningTeam.substr(winningTeam.find(",") + 1);

    prediction.setterRound(roundNumber.substr(0, roundNumber.find(",")));

    predictionRoundNumber = prediction.getterRound();

    if (predictionRoundNumber.empty() == true) {
      prediction.setterRound("0");
    }

    predictionRoundNumber = prediction.getterRound();
    gameNumber = roundNumber.substr(roundNumber.find(",") + 1);

    prediction.setterGameNumber(gameNumber.substr(0, gameNumber.find(",")));

    predictionGameNumber = prediction.getterGameNumber();

    if (predictionGameNumber.empty() == true) {
      prediction.setterGameNumber("0");
    }

    predictionGameNumber = prediction.getterGameNumber();
  }
}

int main() {
  //vectors that store data from csv file
  vector<string> regionData;
  vector<string> rank1Data;
  vector<string> team1Data;
  vector<string> score1Data;
  vector<string> rank2Data;
  vector<string> team2Data;
  vector<string> score2Data;
  vector<string> winningTeamData;
  vector<string> roundNumberData;
  vector<string> gameNumberData;

  string userFile; //user input for file name
  int userOption; //user input for user option
  bool condition = false; //boolean condition for menu option while lop

//clears vectors that store csv file data
  regionData.clear();
  rank1Data.clear();
  team1Data.clear();
  score1Data.clear();
  rank2Data.clear();
  team2Data.clear();
  score2Data.clear();
  winningTeamData.clear();
  roundNumberData.clear();
  gameNumberData.clear();

  displayInstruction(); //calls displayinstruction function
  cin >> userFile; //saves input from user

  if (userFile == "mens_bracket_2021.csv") { //if user inputs mens 2021 bracket passes into readfile function
    readInFile("mens_bracket_2021.csv", regionData, rank1Data, team1Data,
               score1Data, rank2Data, team2Data, score2Data, winningTeamData,
               roundNumberData, gameNumberData);
    condition = true; //changes boolean to true
  }

  else if (userFile == "mens_bracket_2022.csv") { //if user inputs mens 2022 bracket passes into readfile function
    readInFile("mens_bracket_2022.csv", regionData, rank1Data, team1Data,
               score1Data, rank2Data, team2Data, score2Data, winningTeamData,
               roundNumberData, gameNumberData);
    condition = true; //changes boolean to true
  }

  else if (userFile == "womens_bracket_2022.csv") { //if user inputs womens 2022 bracket passes into readfile function
    readInFile("womens_bracket_2022.csv", regionData, rank1Data, team1Data,
               score1Data, rank2Data, team2Data, score2Data, winningTeamData,
               roundNumberData, gameNumberData);
    condition = true; //changes boolean to true
  }

  while (condition) { //while loop for menu options
    menuOption(); //calls menu option function
    cout << "Your choice --> ";
    cin >> userOption; //saves user option for menu options
    if (userOption == 1) { //if user selects first menu option
      vector<string> option1Region; //vector for regions
      vector<string> option1Team; //vector for team names

      //clears vectors
      option1Region.clear();
      option1Team.clear();

      cout << "Total number of games played in tournament: " << regionData.size() << endl;
      cout << "The Final Four contestants are:" << endl;
      for (int i = 3; i < regionData.size(); i++) { //for loop to save unique region names and winner from each region
        if (roundNumberData[i] == "4") {
          if (find(option1Region.begin(), option1Region.end(), regionData[i]) == option1Region.end()) {
            option1Region.push_back(regionData[i]);
            option1Team.push_back(winningTeamData[i]);
          }
        }
      }
      for (int j = 0; j < option1Region.size(); j++) { //outputs data found
        cout << "\t" << option1Region[j] << " region: " << option1Team[j]
             << endl;
      }
      cout << endl;
    }

    else if (userOption == 2) { //if user selects menu option 2 
      //vectors for menu option 2 data
      vector<string> option2RoundNumber;
      vector<string> option2GameNumber;
      vector<string> option2Team1;
      vector<string> option2Team2;
      vector<string> option2GameWinner;

      //clears vectors within menu option 2
      option2GameNumber.clear();
      option2RoundNumber.clear();
      option2Team1.clear();
      option2Team2.clear();
      option2GameWinner.clear();

      cout << "Path to the championship:" << endl;
      for (int i = 0; i < regionData.size(); i++) { //finds winning team path by finding the winning team of championship then comparing it to the winners of all games
        if (winningTeamData[0] == winningTeamData[i]) {
          for (int j = 0; j < 7; j++) {
            if (stoi(roundNumberData[i]) == j) { //push back data from each round of winning team
              option2RoundNumber.push_back(roundNumberData[i]);
              option2GameNumber.push_back(gameNumberData[i]);
              option2Team1.push_back(team1Data[i]);
              option2Team2.push_back(team2Data[i]);
              option2GameWinner.push_back(winningTeamData[i]);
            }
          }
        }
      }
      for (int i = option2RoundNumber.size() - 1; i >= 0; i--) { //outputs path leading to championship for the winning team
        cout << "Round " << option2RoundNumber[i] << ", Game "
             << option2GameNumber[i] << ": " << option2Team1[i] << " vs "
             << option2Team2[i] << ". Winner: " << option2GameWinner[i] << endl;
      }
      cout << endl;
    }

    else if (userOption == 3) { //if user chooses menu option 3
      int roundInput; //saves round input from user
      int min = 0; //saves lowest rank
      //vectors to save region data and total region ranks
      vector<int> regionTotal;
      vector<string> option3Region;

      //clears vectors
      option3Region.clear();
      regionTotal.clear();

      //outputs options for user to select from
      cout << "Enter a round to be evaluated: " << endl;
      cout << "\tSelect 2 for round 2" << endl;
      cout << "\tSelect 3 for round 3 \'Sweet 16\'" << endl;
      cout << "\tSelect 4 for round 4 \'Elite 8\'" << endl;
      cout << "\tSelect 5 for round 5 \'Final 4\'" << endl;
      cout << "Your choice --> ";
      cin >> roundInput; //saves user input option for round

      for (int i = 3; i < regionData.size(); i++) { //finds unique region names
        if (find(option3Region.begin(), option3Region.end(), regionData[i]) ==
            option3Region.end()) {
          option3Region.push_back(regionData[i]);
        }
      }

      if (roundInput != 5) { //if user input is not round 5 then finds the region most likely to win
        cout << "Analyzing round " << roundInput << "..." << endl << endl;
        for (int i = 0; i < 4; i++) {
          int region = 0;
          for (int j = 0; j < regionData.size(); j++) {
            if (option3Region[i] == regionData[j]) {
              if (stoi(roundNumberData[j]) == roundInput) { // if round number is equal to user input then checks for specific round
                if (winningTeamData[j] == team1Data[j]) {  //saves ranks of specific regions
                  region += stoi(rank1Data[j]);
                } else {
                  region += stoi(rank2Data[j]);
                }
              }
            }
          }
          regionTotal.push_back(region); //passes total of rank per region into vector
        }
        for (int i = 0; i < regionTotal.size(); i++) { //saves default value for min variable
          if (regionTotal[i] != 0) {
            min = regionTotal[i];
            break;
          }
        }

        for (int i = 0; i < regionTotal.size(); i++) { //finds the lowest total rank 
          if (regionTotal[i] < min) {
            min = regionTotal[i];
          }
        }

        for (int i = 0; i < regionTotal.size(); i++) { //outputs region most likely to win based on min variable data
          if (regionTotal[i] == min) {
            cout << "The region expected to win is: " << option3Region[i]
                 << endl;
            break;
          }
        }
      } else if (roundInput == 5) { // if user selects round 5
        int min = 0;
        string highestRank;
        vector<int> rankNumber;
        vector<string> teamNames;

        rankNumber.clear();
        teamNames.clear();

        cout << "Analyzing round " << roundInput << "..." << endl << endl;
        for (int i = 0; i < regionData.size(); i++) { //saves name of team and rank if rounnd number matches user selected round number
          if (stoi(roundNumberData[i]) == roundInput) {
            if (winningTeamData[i] == team1Data[i]) {
              rankNumber.push_back(stoi(rank1Data[i]));
              teamNames.push_back(team1Data[i]);
            } else {
              rankNumber.push_back(stoi(rank2Data[i]));
              teamNames.push_back(team2Data[i]);
            }
          }
        }
        for (int i = 0; i < rankNumber.size(); i++) { //sets default min variable
          if (rankNumber[i] != 0) {
            min = rankNumber[i];
            break;
          }
        }

        for (int i = 0; i < rankNumber.size(); i++) { //finds lowest rank from rank number vector
          if (rankNumber[i] < min) {
            min = rankNumber[i];
          }
        }
        for (int i = 0; i < rankNumber.size(); i++) { //finds highest rank team name based off min variable
          if (rankNumber[i] == min) {
            highestRank = teamNames[i];
          }
        }
        for (int i = 3; i < team1Data.size(); i++) { //outputs data if highest rank team name matches from csv file
          if (team1Data[i] == highestRank) {
            cout << "The region expected to win is: " << regionData[i] << endl;
            break;
          }
        }
      }
    } else if (userOption == 4) { // if user selects menu option 4
      int roundNum; //saves user input for round number
      int max = 0; //max variable
      vector <int> rankNum; //saves rank numbers
      vector <string> teamName; //saves team names
      vector<int> finalRanks; //saves final ranks after all calcuations are done
      vector <string> finalTeam; //saves final team name after all calculations are done

      //clears all vectors
      rankNum.clear();
      teamName.clear();
      finalRanks.clear();
      finalTeam.clear();

      //outputs round number options
      cout << "Enter a round to be evaluated: " << endl;
      cout << "\tSelect 2 for round 2" << endl;
      cout << "\tSelect 3 for round 3 \'Sweet 16\'" << endl;
      cout << "\tSelect 4 for round 4 \'Elite 8\'" << endl;
      cout << "\tSelect 5 for round 5 \'Final 4\'" << endl;
      cout << "\tSelect 6 for round 6 \'Championship\'" << endl;
      cout << "Your choice --> ";
      cin >> roundNum; //saves user choice for round number

      for (int i = 0; i < regionData.size(); i++) { //if round number from csv file matches user input saves data from that specific round number
        if (stoi(roundNumberData[i]) == roundNum) {
          rankNum.push_back(stoi(rank1Data[i]));
          teamName.push_back(team1Data[i]);
          rankNum.push_back(stoi(rank2Data[i]));
          teamName.push_back(team2Data[i]);
        }
      }
      if (roundNum != 5 || roundNum!= 6) { //if round number is not 5 or 6
        for (int i = 0; i < rankNum.size(); i++) { // finds duplicates of data
          if (find(finalTeam.begin(), finalTeam.end(), teamName[i]) ==
            finalTeam.end()) {
            finalTeam.push_back(teamName[i]);
            finalRanks.push_back(rankNum[i]);
          }
        }
        for (int i = 0; i < finalRanks.size(); i++) { // sets max variable default value
          if (finalRanks[i] != 0) {
            max = finalRanks[i];
            break;
          }
        }

        for (int i = 0; i < finalRanks.size(); i++) { //finds max value from given ranks
          if (finalRanks[i] > max) {
            max = finalRanks[i];
          }
        }
      }
      if (roundNum == 5 || roundNum == 6) { //if user selects round 5 or 6
        for (int i = 0; i < regionData.size(); i++) { //saves data if round number matches user selected round number
        if (stoi(roundNumberData[i]) == roundNum) {
          rankNum.push_back(stoi(rank1Data[i]));
          teamName.push_back(team1Data[i]);
          rankNum.push_back(stoi(rank2Data[i]));
          teamName.push_back(team2Data[i]);
        }
      }
        for (int i = 0; i < finalRanks.size(); i++) {//sets default value for max variable
          if (finalRanks[i] != 0) {
            max = finalRanks[i];
            break;
          }
        }

        for (int i = 0; i < finalRanks.size(); i++) { //finds max rank
          if (finalRanks[i] > max) {
            max = finalRanks[i];
          }
        }
      }
        for (int i = 0; i < finalRanks.size(); i++) { //outputs data if csv file data matches max rank variable
          if (finalRanks[i] == max) {
            cout << "The best underdog team is " << finalTeam[i] << " which has rank " << finalRanks[i] << "." << endl;
            break;
          }
        }
    } else if (userOption == 5) { //if user selects menu option 5
      int max = 0; //saves max differene in scores
      int min = 0; //saves min difference in scores
      int userChoice; //saves user choice for round number

      vector <int> option5RoundNumber; //saves round numbers
      vector <int> option5GameNum; //saves game numbers
      vector <string> option5Team1; //saves team 1 name
      vector <string> option5Team2; //saves team 2 name
      vector <string> option5Winner; //saves winner of given game
      vector <int> option5Score1; //saves score of team 1 from csv file
      vector <int> option5Score2; //saves score of team 2 from csv file
      vector <int> difference; //saves difference in scores

      //clears all vectors
      option5GameNum.clear();
      option5RoundNumber.clear();
      option5Team1.clear(); 
      option5Team2.clear();
      option5Winner.clear();
      option5Score1.clear();
      option5Score2.clear();
      difference.clear(); 

      //outputs user options for rounds
      cout << "Enter a round to be evaluated:" << endl;
      cin >> userChoice;
      cout << "\tSelect 1 for round 1" << endl;
      cout << "\tSelect 2 for round 2" << endl;
      cout << "\tSelect 3 for round 3 \'Sweet 16\'" << endl;
      cout << "\tSelect 4 for round 4 \'Elite 8\'" << endl;
      cout << "\tSelect 5 for round 5 \'Final 4\'" << endl;
      cout << "\tSelect 6 for round 6 \'Championship\'" << endl;
      cout << "\tSelect 7 for the overall tournament" << endl;

      if (userChoice != 7) { //if round number is not 7
        cout << "Your choice --> Analyzing round " << userChoice << "..." << endl << endl;
        for (int i = 0; i < regionData.size(); i++) {
          if (stoi(roundNumberData[i]) == userChoice) { //saves data if round number matches user input of round number
            option5RoundNumber.push_back(stoi(roundNumberData[i]));
            option5GameNum.push_back(stoi(gameNumberData[i]));
            option5Team1.push_back(team1Data[i]);
            option5Team2.push_back(team2Data[i]);
            option5Winner.push_back(winningTeamData[i]);
            option5Score1.push_back(stoi(score1Data[i]));
            option5Score2.push_back(stoi(score2Data[i]));
          }
        }
      }
      else if (userChoice == 7) { //if user selects round 7
        cout << "Your choice --> Analyzing the overall tournament..." << endl << endl;
        for (int i = 0; i < regionData.size(); i++) {
          option5RoundNumber.push_back(stoi(roundNumberData[i]));
          option5GameNum.push_back(stoi(gameNumberData[i]));
          option5Team1.push_back(team1Data[i]);
          option5Team2.push_back(team2Data[i]);
          option5Winner.push_back(winningTeamData[i]);
          option5Score1.push_back(stoi(score1Data[i]));
          option5Score2.push_back(stoi(score2Data[i]));
        }
      }
        for (int i = 0; i < option5Score1.size(); i++) { //decides which score to substract from to avoid negative scores
          if (option5Score1[i] > option5Score2[i]) {
            difference.push_back(option5Score1[i] - option5Score2[i]);
          }
          else {
            difference.push_back(option5Score2[i] - option5Score1[i]);
          }
        }

        for (int i = 0; i < difference.size(); i++) { //sets default value for max variable
          if (difference[i] != 0) {
            max = difference[i];
            break;
          }
        }
        for (int i = 0; i < difference.size(); i++) { //sets default value for min variable
          if (difference[i] != 0) {
            min = difference[i];
            break;
          }
        }

        for (int i = 0; i < difference.size(); i++) { //finds max difference in scores
          if (difference[i] > max && difference[i] > 0) {
            max = difference[i];
          }
        }

        for (int i = 0; i < difference.size(); i++) { //finds min difference in scores
          if (difference[i] < min && difference[i] > 0) {
            min = difference[i];
          }
        }
      cout << "The shoo-in game was:" << endl;//outputs greatest difference in scores
      for (int i = 0; difference.size(); i++){
        if (difference[i] == max) {
          cout << "Round " << option5RoundNumber[i] << ", Game " << option5GameNum[i] << ": " << option5Team1[i] << " vs " << option5Team2[i] << ". Winner: " << option5Winner[i] << endl;
        break;
        }
      }
      cout << "The difference was " << max << " points." << endl << endl;
      
      cout << "The nail-biting game was:" << endl; //outputs lowest difference in scores
      for (int i = 0; difference.size(); i++){
        if (difference[i] == min) {
          cout << "Round " << option5RoundNumber[i] << ", Game " << option5GameNum[i] << ": " << option5Team1[i] << " vs " << option5Team2[i] << ". Winner: " << option5Winner[i] << endl;
        break;
        }
      }
      cout << "The difference was " << min << " points." << endl << endl;

    } else if (userOption == 6) { //if user selects menu option 6
      string predictionFile; //saves file name from user input
      int correctGames = 0; //counter for number of games corretly guessed
      int score = 0; //saves score of predicted bracket

      //vectors for data from predicition csv file
      vector<string> predictionRegion;
      vector<string> predictionRank1;
      vector<string> predictionTeam1;
      vector<string> predictionScore1;
      vector<string> predictionRank2;
      vector<string> predictionTeam2;
      vector<string> predictionScore2;
      vector<string> predictionWinningTeam;
      vector<string> predictionRoundNumber;
      vector<string> predictionGameNumber;
    

    //clears all prediction data vectors
      predictionRegion.clear();
      predictionRank1.clear();
      predictionTeam1.clear();
      predictionScore1.clear();
      predictionRank2.clear();
      predictionTeam2.clear();
      predictionScore2.clear();
      predictionWinningTeam.clear();
      predictionRoundNumber.clear();
      predictionGameNumber.clear();

      cout << "Enter the name of the file with your predicted brackets: ";//passes in csv file based on input of user for which csv file to use
      cin >> predictionFile;
      if (predictionFile == "womens_bracket_2022_predictions1.csv") { //if user selects womens predicted bracket
  readInFile2("womens_bracket_2022_predictions1.csv", predictionRegion, predictionRank1, predictionTeam1, predictionScore1, predictionRank2, predictionTeam2, predictionScore2, predictionWinningTeam, predictionRoundNumber, predictionGameNumber);
      }

      else if (predictionFile == "mens_bracket_2022_predictions1.csv") { //if user selects mens 2022 predicted bracket
  readInFile2("mens_bracket_2022_predictions1.csv", predictionRegion, predictionRank1, predictionTeam1, predictionScore1, predictionRank2, predictionTeam2, predictionScore2, predictionWinningTeam, predictionRoundNumber, predictionGameNumber);
      }

      else if (predictionFile == "mens_bracket_2021_predictions2.csv") { //if user selects mens 2021 #1 predicted bracket
  readInFile2("mens_bracket_2021_predictions2.csv", predictionRegion, predictionRank1, predictionTeam1, predictionScore1, predictionRank2, predictionTeam2, predictionScore2, predictionWinningTeam, predictionRoundNumber, predictionGameNumber);
      }

      else if (predictionFile == "mens_bracket_2021_predictions1.csv") { //if user selects mens 2021 #2 predicted bracket
  readInFile2("mens_bracket_2021_predictions1.csv", predictionRegion, predictionRank1, predictionTeam1, predictionScore1, predictionRank2, predictionTeam2, predictionScore2, predictionWinningTeam, predictionRoundNumber, predictionGameNumber);
      }

    for (int i = 0; i < regionData.size(); i++) {
      if (winningTeamData[i] == predictionWinningTeam[i]) { //if user selects winning team correctly
        correctGames++; //increases counter
        score += (5*stoi(roundNumberData[i])); //calcualtes score user
      }
    }
    cout << "You correctly predicted the winner for " <<     correctGames << " games." << endl; //outputs number of correctly guessed correctGames
    cout << "This means that you have a score of " << score << "." << endl; 
    if (score >= 250) { //output if score is greater than 250
    cout << "Great job! You could consider entering your predictions to win money!" << endl;
    }
    else { //output if score is less than 250
      cout << "You may want to learn more about basketball to improve your predictions next year." << endl;
    }

    } else if (userOption == 7) { //if user choices menu option 7
      cout << "Exiting program...";
      break; //breaks out of while loop
    }
    else { //if user incoretly chooses menu option
      cout << "Invalid value.  Please re-enter a value from the menu options below." << endl << endl;
    }
  }

  return 0;
}