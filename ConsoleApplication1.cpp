#include<iostream>
#include<memory>
#include<vector>
#include<list>
#include<sstream>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	int stuno;
	string name;
	void showMe();
	static int currentNO;
};
int Student::currentNO = 10000;
Student::Student()
{
	stuno = currentNO++;
}

Student::~Student()
{

}

void Student::showMe()
{
	cout << stuno << " " << name << endl;
}




class Team
{
public:
	Team();
	~Team();
	list<Student*> students;
	string teamName;
	void addStudent(Student* student);
	void printInfo();
};
Team::Team()
{

}
Team::~Team()
{
	list<Student*>::iterator iter;
	for (iter = students.begin(); iter != students.end(); iter++)
	{
		Student* student = *iter;
		if (student != NULL)
		{
			free(student);
			student = NULL;
		}
	}
}

void Team::addStudent(Student* student)
{
	students.push_back(student);
	// cout<<"add student "<<student->name<<" success"<<endl;
}


void Team::printInfo()
{
	list<Student*>::iterator iter;
	cout << this->teamName << " team" << ":" << endl;
	for (iter = students.begin(); iter != students.end(); iter++)
	{
		Student* student = *iter;
		student->showMe();
	}
	cout << endl;
}




class Clazz
{
public:
	Clazz();
	~Clazz();
	list<Student*> students;
	string className;
	void addStudent(Student* student);
	void printInfo();
};
Clazz::Clazz()
{

}
Clazz::~Clazz()
{
	list<Student*>::iterator iter;
	for (iter = students.begin(); iter != students.end(); iter++)
	{
		Student* student = *iter;
		if (student != NULL)
		{
			free(student);
			student = NULL;
		}
	}
}
void Clazz::addStudent(Student* student)
{
	students.push_back(student);
	// cout<<"add student "<<student->name<<" success"<<endl;
}
void Clazz::printInfo()
{
	list<Student*>::iterator iter;
	cout << "class " << this->className << ":" << endl;
	for (iter = students.begin(); iter != students.end(); iter++)
	{
		Student* student = *iter;
		student->showMe();
	}
	cout << endl;
}

class Command
{
public:
	Command();
	~Command();
	list<Student*> students;
	list<Clazz*> clazzs;
	list<Team*> teams;
	void createStudent(string studentname);
	void createTeam(string teamname);
	void createClazz(string classname);
	void parseCommad(string commandStr);
	void showOptions();
	Team* getTeam(string teamname);
	Clazz* getClazz(string classname);
	Student* getStudent(string studentname);
	Student* getStudent(int studentno);
	bool isNumberForInt(string str);
	int parsetInt(string str);
	void printInfo();


};

Command::Command()
{

}

Command::~Command()
{
	list<Student*>::iterator stuIter;
	list<Team*>::iterator teamIter;
	list<Clazz*>::iterator clazzIter;

	for (stuIter = students.begin(); stuIter != students.end(); stuIter++)
	{
		Student* student = *stuIter;
		if (student != NULL)
		{
			free(student);
			student = NULL;
		}

	}

	for (teamIter = teams.begin(); teamIter != teams.end(); teamIter++)
	{
		Team* team = *teamIter;
		if (team != NULL)
		{
			free(team);
			team = NULL;
		}

	}

	for (clazzIter = clazzs.begin(); clazzIter != clazzs.end(); clazzIter++)
	{
		Clazz* clazz = *clazzIter;
		if (clazz != NULL)
		{
			free(clazz);
			clazz = NULL;
		}

	}
}


void Command::createStudent(string studentname)
{
	Student* student = new Student;
	student->name = studentname;
	// cout << student -> name <<endl;
	students.push_back(student);
}
void Command::createTeam(string teamname)
{
	Team* team = new Team;
	team->teamName = teamname;
	teams.push_back(team);
}
void Command::createClazz(string classname)
{
	Clazz* clazz = new Clazz;
	clazz->className = classname;
	clazzs.push_back(clazz);
}

void Command::parseCommad(string commandStr)
{

	string appendCommand = "append";
	string createCommand = "create";
	string joinCommand = "join";
	string teamCommand = "team";
	string classCommand = "class";
	if (commandStr.empty())
	{
		return;
	}
	// cout<<"comdstr"<<commandStr<<endl;
	istringstream is(commandStr);
	int index = 0;
	int type = 0;//0涓篹xit 1涓篴ppend 2涓篶reate 3涓簀oin 4涓篶reate class 5涓篶reate team 6涓簀oin class  7涓簀oin team
	string word;
	string stuname;
	string classname;
	string teamname;
	int stuno = 0;
	while (is >> word)
	{

		switch (index)
		{
		case 0:
		{
			// cout<< word<<endl;
			if (appendCommand.compare(word) == 0)
			{
				type = 1;
				break;
			}
			else if (createCommand.compare(word) == 0)
			{
				type = 2;
				break;
			}
			else if (joinCommand.compare(word) == 0)
			{
				type = 3;
				break;
			}
			else
			{

				// cout<<"error command:"<<word<<endl;
				is.clear();
				return;
			}
			break;
		}
		case 1:
		{
			if (type == 1)
			{
				// cout<<"word:"<<word<<endl;
				stuname = word;
				break;
			}
			else if (type == 2)
			{
				if (classCommand.compare(word) == 0)
				{
					type = 4;
					break;
				}
				else if (teamCommand.compare(word) == 0)
				{
					type = 5;
					break;
				}
				else
				{
					// cout<<"error command:"<<word<<endl;
					is.clear();
					return;
				}
				break;
			}
			else if (type == 3)
			{
				// cout<<word<<endl;
				if (classCommand.compare(word) == 0)
				{
					type = 6;
					break;

				}
				else if (teamCommand.compare(word) == 0)
				{
					type = 7;
					break;

				}
				else
				{
					cout << "error command:" << word << endl;
					is.clear();
					return;
				}
			}
			break;

		}
		case 2:
		{

			if (type == 4 || type == 6)
			{
				classname = word;
				break;

			}
			else if (type == 5 || type == 7)
			{
				teamname = word;
				break;
			}
			else
			{
				cout << "error command:" << word << endl;
				is.clear();
				return;
			}
			break;

		}
		case 3:
		{
			if (type == 6 || type == 7)
			{
				if (!isNumberForInt(word))
				{
					cout << "valid studentNO:" << word << endl;
					is.clear();
					return;
				}
				stuno = parsetInt(word);
				break;
			}
			else
			{
				cout << "the Command is Error to end" << word << endl;
				is.clear();
				return;
			}
			break;
		}
		default:
		{
			cout << "the Command is Error to end" << word << endl;
			is.clear();
			return;
		}

		}

		index++;
	}


	is.clear();
	// cout<<index<<endl;
	switch (type)
	{
	case 1:
	{
		// cout<<"stuname"<<stuname<<endl;
		createStudent(stuname);
		// cout<<"create student success"<<endl;
		break;
	}
	case 4:
	{
		Clazz* clazz = getClazz(classname);
		if (clazz != NULL)
		{
			cout << "the class exists:" << classname << endl;
			return;
		}
		createClazz(classname);
		// cout<<"create class success"<<endl;
		break;
	}
	case 5:
	{
		Team* team = getTeam(teamname);
		if (team != NULL)
		{
			cout << "the team exists:" << teamname << endl;
			return;
		}
		createTeam(teamname);
		// cout<<"create team success"<<endl;
		break;
	}
	case 6:
	{
		Clazz* clazz = getClazz(classname);
		Student* student = getStudent(stuno);
		if (clazz == NULL)
		{
			cout << "the class not exists:" << teamname << endl;
			return;
		}
		if (student == NULL)
		{
			cout << "the student not exists:" << stuno << endl;
			return;
		}
		clazz->addStudent(student);
		break;
	}
	case 7:
	{
		Team* team = getTeam(teamname);
		Student* student = getStudent(stuno);
		if (team == NULL)
		{
			cout << "the team not exists:" << teamname << endl;
			return;
		}
		if (student == NULL)
		{
			cout << "the student not exists:" << stuno << endl;
			return;
		}
		team->addStudent(student);
		break;
	}
	default:
	{
		cout << "the Command is Error to end" << word << endl;
		break;
	}

	}

	// cout<<"end command" << endl;


}
void Command::showOptions()
{
	string exitString = "exit";
	string commandStr;
	while (getline(cin, commandStr))
	{

		// char comandChars[200];
		// cout<<"studentsystem>:";
		// cin.getline(comandChars,200);

		if (exitString.compare(commandStr) == 0)
		{
			return;
		}
		parseCommad(commandStr);
		// cin.clear();
	}
}

Team* Command::getTeam(string teamname)
{
	list<Team*>::iterator teamIter;
	for (teamIter = teams.begin(); teamIter != teams.end(); teamIter++)
	{
		Team* team = *teamIter;
		if (team != NULL && (teamname.compare(team->teamName) == 0))
		{
			return team;
		}
	}
	return NULL;
}
Clazz* Command::getClazz(string classname)
{
	list<Clazz*>::iterator clazzIter;
	for (clazzIter = clazzs.begin(); clazzIter != clazzs.end(); clazzIter++)
	{
		Clazz* clazz = *clazzIter;
		if (clazz != NULL && (classname.compare(clazz->className) == 0))
		{
			return clazz;
		}
	}

	return NULL;
}
Student* Command::getStudent(string studentname)
{
	list<Student*>::iterator stuIter;
	for (stuIter = students.begin(); stuIter != students.end(); stuIter++)
	{
		Student* student = *stuIter;
		if (student != NULL && (studentname.compare(student->name) == 0))
		{
			return student;
		}

	}
	return NULL;
}
Student* Command::getStudent(int studentno)
{
	list<Student*>::iterator stuIter;
	for (stuIter = students.begin(); stuIter != students.end(); stuIter++)
	{
		Student* student = *stuIter;
		if (student != NULL && (studentno == student->stuno))
		{
			return student;
		}
	}

	return NULL;
}

bool Command::isNumberForInt(string str)
{
	stringstream sin(str);
	int number;
	if (!(sin >> number))
	{
		sin.clear();
		return false;
	}
	sin.clear();
	return true;
}
int Command::parsetInt(string str)
{
	stringstream sin(str);
	int number;
	if (!(sin >> number))
	{
		sin.clear();
		return -1;
	}
	sin.clear();
	return number;
}
void Command::printInfo()
{
	cout << "student list:" << endl;
	list<Student*>::iterator stuIter;
	for (stuIter = students.begin(); stuIter != students.end(); stuIter++)
	{
		Student* student = *stuIter;
		if (student != NULL)
		{
			student->showMe();
		}
	}

	cout << endl;
	// cout<<"class list:"<<endl;
	list<Clazz*>::iterator clazzIter;
	for (clazzIter = clazzs.begin(); clazzIter != clazzs.end(); clazzIter++)
	{
		Clazz* clazz = *clazzIter;
		if (clazz != NULL)
		{
			clazz->printInfo();
		}
	}
	// cout<<endl;
	// cout<<"team list:"<<endl;
	list<Team*>::iterator teamIter;
	for (teamIter = teams.begin(); teamIter != teams.end(); teamIter++)
	{
		Team* team = *teamIter;
		if (team != NULL)
		{
			team->printInfo();
		}
	}


}
int main()
{
	Command* command = new Command;
	command->showOptions();
	command->printInfo();
	//free(command);
	command = NULL;
	return 0;
}