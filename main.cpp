using namespace std;
#include <iostream>
#include<string>
#include <ctime>


enum enQuestionLevel { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Substract = 2, Multiply = 3, Divide = 4, MixOp = 5 };

struct stRound
{
    short NumOfQuestion;
    short LevelType;
    short OpType;
};
struct stQuestion
{
    int FirstNum;
    char Operation;
    int SecondNum;
    int Result;

};
struct stScore
{
    int RightAnswer = 0;
    int WrongAnswer = 0;

};

int ReadNum(string message)
{
    int num;
    cout << message;
    cin >> num;
    return num;

}

int RandomNum(int from, int to)
{

    return rand() % (to - from + 1) + from;

}

void TakeInputs(stRound& Round)
{
    Round.NumOfQuestion = ReadNum("How many Questions do you want to answer ?  ");
    Round.LevelType = ReadNum("Enter Question level [1] Esay , [2] Mid , [3] Hard , [4] Mix ?  ");
    Round.OpType = ReadNum("Enter Operation Type [1] Add , [2] Sub , [3] Mul , [4] Div , [5] Mix ?  ");

}

int MixOperations()
{

    int arr[] = { 42, 43 , 45 , 47 };   // { * , + , - , / }
    int index = rand() % 4;
    int randomOp = arr[index];
    return randomOp;


}

int MixLevel()
{
    int arrMixLevel[] = { RandomNum(1,10) ,RandomNum(1,50) , RandomNum(1,100) };
    int index = rand() % 3;
    int MixLevel = arrMixLevel[index];
    return MixLevel;

}

char OpSymbol(short num)
{
    switch (num)
    {
    case(enOperationType::Add):
        return '+';
    case(enOperationType::Substract):
        return '-';
    case(enOperationType::Multiply):
        return '*';
    case(enOperationType::Divide):
        return'/';
    case(enOperationType::MixOp):
        return char(MixOperations());
    default:
        return '!';


    }

}

int QuestionNumbers(short num)
{
    switch (num)
    {
    case(enQuestionLevel::Easy):
        return (RandomNum(1, 10));

    case (enQuestionLevel::Mid):
        return (RandomNum(1, 50));

    case(enQuestionLevel::Hard):
        return(RandomNum(1, 100));

    case(enQuestionLevel::Mix):
        return(MixLevel());


    }

}

string LevelChoice(int num)
{
    switch (num)
    {
    case(enQuestionLevel::Easy):
        return "Easy";

    case(enQuestionLevel::Mid):
        return"Mid";

    case(enQuestionLevel::Hard):
        return "Hard";

    case(enQuestionLevel::Mix):
        return "Mix";

    default:
        return "Unknown Level";

    }

}

string OperationChoice(int num)
{
    switch (num)
    {
    case(enOperationType::Add):
        return "Addition";

    case(enOperationType::Substract):
        return "Substraction";

    case(enOperationType::Multiply):
        return "Multiplication";

    case(enOperationType::Divide):
        return "Division";

    case(enOperationType::MixOp):
        return "Mix";

    default:
        return "Unknown operation";

    }

}

int CalculateResult(stQuestion Question)
{
    switch (Question.Operation)
    {
    case('+'):
        return (Question.FirstNum + Question.SecondNum);

    case('-'):
        return (Question.FirstNum - Question.SecondNum);

    case('*'):
        return (Question.FirstNum * Question.SecondNum);

    case('/'):
        return (Question.FirstNum / Question.SecondNum);

    default:
        return 0;

    }

}

void UpdateScore(int Result, int UserAnswer, stScore& Score)
{


    if (Result == UserAnswer)
    {
        system("color 2F");
        cout << "\nRight Answer :-)\n";
        Score.RightAnswer++;
    }
    else
    {
        system("color 4F");
        cout << "\nWrong Answer :-(\n";
        cout << "\nThe right answer is : " << Result << endl;
        Score.WrongAnswer++;



    }

}


void Questions(stRound Round, stScore& Score)
{
    int UserAnswer = 0;

    stQuestion Question;

    for (int i = 1; i <= Round.NumOfQuestion; i++)
    {
        cout << "\nQuestion [" << i << "/" << Round.NumOfQuestion << "]\n";
        cout << "------------------\n\n";


        Question.FirstNum = QuestionNumbers(Round.LevelType);
        Question.Operation = OpSymbol(Round.OpType);

        do
        {
            Question.SecondNum = QuestionNumbers(Round.LevelType);

        } while (Question.SecondNum == 0 && Question.Operation == '/');


        Question.Result = CalculateResult(Question);

        cout << " " << Question.FirstNum << " ";
        cout << Question.Operation << " " << Question.SecondNum << " = ";
        cin >> UserAnswer;

        
        UpdateScore(Question.Result, UserAnswer, Score);

        cout << "-------------------------------";



    }


}

string PassOrFail(stScore Score)
{
    if (Score.RightAnswer > Score.WrongAnswer)
    {
        return "PASS";
    }
    else if (Score.RightAnswer < Score.WrongAnswer)
    {
        return "Fail";
    }
    else
    {
        return "Try Again";
    }

}



void ShowFinalResults(stRound Round, stScore Score)
{

    cout << "\n\n-----------------------------------------------------------";
    cout << "\n  Final Results is " << PassOrFail(Score);
    cout << "\n-------------------------------------------------------------\n";
    cout << "\nNumber of Questions     : " << Round.NumOfQuestion;
    cout << "\nQuestions Level         : " << LevelChoice(Round.LevelType);
    cout << "\nOperation Type          : " << OperationChoice(Round.OpType);
    cout << "\nNumber of Right Answers : " << Score.RightAnswer;
    cout << "\nNumber of Wrong Answers : " << Score.WrongAnswer;
    cout << "\n\n--------------------------------------------------------------\n";






}

void StartGame()
{
    char PlayAgain;
    do
    {
        stRound Round;
        stScore Score;
        TakeInputs(Round);
        Questions(Round, Score);
        ShowFinalResults(Round, Score);

        cout << "\n\nDo you want to play again ? Y/N ?  ";
        cin >> PlayAgain;

        system("color 0F");
        system("cls");


    } while (PlayAgain == 'Y' || PlayAgain == 'y');


}



int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    //Test Commit 
}

