#include "Laba3.h"

int GenerateINT()
{
	return rand();
}

double GenerateDOUBLE()
{
	return (double)(rand() % 10) + (double)(rand() % 10) / 10.0;
}

/*string GenerateUUID()
{
	UUID uuid;
	UuidCreate(&uuid);
	char* str;
	UuidToStringA(&uuid, (RPC_CSTR*)&str);
	return (string)str;
	//RpcStringFreeA((RPC_CSTR*)&str);
}*/


void GeneratePeople(Sequence<Person>* seq, int size)
{
    srand(time(0));

    vector<string> names = {
        "Alexander", "Alexey", "Anatoly", "Andrey", "Anton", "Arkady", "Arseny",
        "Artem", "Boris", "Vadim", "Valentin", "Valery", "Vasily", "Victor",
        "Vitaly", "Vladimir", "Vladislav", "Vyacheslav", "Gennady", "George",
        "Gleb", "Gregory", "David", "Daniel", "Denis", "Dmitry", "Eugene", "Egor",
        "Ivan", "Igor", "Ilya", "Kirill", "Konstantin", "Lev", "Leonid", "Maxim",
        "Mark", "Matthew", "Mikhail", "Nikita", "Nikolai", "Oleg", "Pavel", "Peter",
        "Roman", "Ruslan", "Sergey", "Stanislav", "Stepan", "Timofey", "Fedor", "Yuri",
        "Yakov", "Yaroslav"
    };

    vector<string> surnames = {
        "Ivanov", "Smirnov", "Kuznetsov", "Popov", "Vasilyev", "Petrov", "Sokolov", "Mikhailov",
        "Novikov", "Fedorov", "Morozov", "Volkov", "Aleksandrov", "Lebedev", "Semenov", "Egorov",
        "Pavlov", "Kozlov", "Stepanov", "Nikolaev"
    };



    for (int i = 0; i < size; i++) {
        int indexName = rand() % 54;
        int indexSurname = rand() % 10;
        int age = rand() % 100;
        int salary = rand() % 10000 + rand() % 20000 + rand() % 30000 + rand() % 40000;
        Person p{ names[indexName], surnames[indexSurname], age, salary };
        seq->Append(p);
    }
    return;
}





