#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enQuizzLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOpType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };
enum enPassOrFail { Pass = 1, Fail = 2 };

struct stQuizz
{
	short NumberOfQuizz = 0;
	string QuizzLevel;
	string OpType;
	short NumberOfRightAnswer = 0;
	short NumberOfWrongAnswer = 0;
	enPassOrFail Result;
};

int RandomNumber(int From, int To) {

	//Function To Generate a random Number :
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

short HowManyQuizz() {

	short NumberOfQuizz = 1;

	cout << "How Many Questions do you want to answer ?  ";
	cin >> NumberOfQuizz;

	return NumberOfQuizz;
}

enQuizzLevel ReadQuizzLevel() {

	short QuizzLevel = 1;

	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?  ";
		cin >> QuizzLevel;
	} while (QuizzLevel < 1 || QuizzLevel > 4);

	return enQuizzLevel(QuizzLevel);
}

enOpType ReadOperationType() {

	short OpType = 1;

	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?  ";
		cin >> OpType;
	} while (OpType < 1 || OpType > 5);

	return enOpType(OpType);
}


void GenerateNumbers(short& Num1, short& Num2, enQuizzLevel QuizLevel){

	switch (QuizLevel) {
	case enQuizzLevel::Easy:
		Num1 = RandomNumber(1, 10);
		Num2 = RandomNumber(1, 10);
		break;
	case enQuizzLevel::Med:
		Num1 = RandomNumber(10, 50);
		Num2 = RandomNumber(10, 50);
		break;
	case enQuizzLevel::Hard:
		Num1 = RandomNumber(50, 100);
		Num2 = RandomNumber(50, 100);
		break;
	case enQuizzLevel::Mix:
		Num1 = RandomNumber(1, 100);
		Num2 = RandomNumber(1, 100);
	}

}

int Calculator(short Num1, short Num2, enOpType OpType) {

	switch (OpType) {
	case enOpType::Add:
		return Num1 + Num2;
	case enOpType::Sub:
		return Num1 - Num2;
	case enOpType::Mul:
		return Num1 * Num2;
	case enOpType::Div:
		if (Num2 == 0)
			return 0;
		else 
			return Num1 / Num2;
	}
}

char OpTypeChar(enOpType OpType) {

	char arrOpType[4] = { '+','-','*','/' };
	return arrOpType[OpType - 1];
}

int ReadPlayerAnswer(short Num1, short Num2, enOpType OpType) {

	int Answer = 0;

	cout << Num1 << endl;
	cout << Num2 << " " << OpTypeChar(OpType) << endl;
	cout << "________________\n";
	cin >> Answer;

	return Answer;
}

void SetBackgroundColor(enPassOrFail Result) {

	switch (Result) {
	case enPassOrFail::Pass:
		system("color 2F");
		break;
	case enPassOrFail::Fail:
		cout << "\b";
		system("color 4F");
		break;
	}
}
	



string OpTypeName(enOpType OpType) {

	string arrOpTypName[5] = { "Add","Sub","Mul","Div","Mix" };
	return arrOpTypName[OpType - 1];
}

string QuizzLevelName(enQuizzLevel QuizzLevel) {

	string arrQuizzLevelName[4] = { "Easy","Med","Hard","Mix" };
	return arrQuizzLevelName[QuizzLevel - 1];
}

string ResultName(enPassOrFail Result) {

	string arrResult[2] = { "Pass :-)","Fail :-(" };
	return arrResult[Result - 1];
}

stQuizz PlayGame(enOpType OpType,enQuizzLevel QuizzLevel,short HowManyQuizz) {

	stQuizz Quizz;
	short RightAnswer = 0, WrongAnswer = 0, Num1 = 0, Num2 = 0;
	int ComputerAnswer = 0, PlayerAnswer = 0;

	for (short Question = 1; Question <= HowManyQuizz; Question++)
	{
		cout << "\nQuestion [" << Question << "/" << HowManyQuizz << "]\n";

		GenerateNumbers(Num1,Num2,QuizzLevel);

		if (OpType == enOpType::MixOp) {
			OpType = enOpType(RandomNumber(1, 4));

			ComputerAnswer = Calculator(Num1, Num2, OpType);
			PlayerAnswer = ReadPlayerAnswer(Num1, Num2, OpType);

			OpType = enOpType::MixOp;
		}
		else {

			ComputerAnswer = Calculator(Num1, Num2, OpType);
			PlayerAnswer = ReadPlayerAnswer(Num1, Num2, OpType);
		}

		
		if (ComputerAnswer == PlayerAnswer) {

			SetBackgroundColor(enPassOrFail::Pass);
			RightAnswer++;
		}
		else
		{
			SetBackgroundColor(enPassOrFail::Fail);
			WrongAnswer++;
		}
	}
	
	Quizz.NumberOfQuizz = HowManyQuizz;
	Quizz.NumberOfRightAnswer = RightAnswer;
	Quizz.NumberOfWrongAnswer = WrongAnswer;
	Quizz.OpType = OpTypeName(OpType);
	Quizz.QuizzLevel = QuizzLevelName(QuizzLevel);
	
	if (RightAnswer >= WrongAnswer)
		Quizz.Result = enPassOrFail::Pass;
	else
		Quizz.Result = enPassOrFail::Fail;

	return Quizz;
}

void ShowFinalResult(stQuizz Quizz) {

	cout << "\n______________________________________\n";
	cout << "\n Final Result is " << ResultName(Quizz.Result);
	cout << "\n______________________________________\n";
	cout << "\nNumber Of Questions : " << Quizz.NumberOfQuizz;
	cout << "\nQuestions Level     : " << Quizz.QuizzLevel;
	cout << "\nOpType              : " << Quizz.OpType;
	cout << "\nNumber Of Right Answer : " << Quizz.NumberOfRightAnswer;
	cout << "\nNumber Of Wrong Answer : " << Quizz.NumberOfWrongAnswer;
	cout << "\n______________________________________\n";

	SetBackgroundColor(Quizz.Result);
}

void ResetScreen() {

	system("color 0F");
	system("cls");
}

void StartGame() {

	char AddMore = 'Y';

	do
	{
		ResetScreen();
		stQuizz Quizz = PlayGame(ReadOperationType(),ReadQuizzLevel(), HowManyQuizz());
		ShowFinalResult(Quizz);

		cout << "\nDo you want To Play Again? Y/N :  ";
		cin >> AddMore;

	} while (AddMore == 'Y' || AddMore == 'y');

}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}

