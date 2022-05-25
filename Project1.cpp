#include <iostream>
#include <string> 
#include <cstdlib> //Рандомайзер




using namespace std;
void rules()
{
    system("cls");//функция,очищающая экран
    cout << "__________________________________________________\n";
    cout << "|\t\tПравила нашей игры:\t\t |\n";
    cout << "|1. Введи ставку\t\t\t\t |\n";
    cout << "|2. Выбери число от одного до десяти\t\t |\n";
    cout << "|3. Если ты выииграл,то получишь удвоенную ставку|\n";
    cout << "|4. Если проиграл,то попрощайся со своей ставкой |";
}


int main()
{
    system("chcp 1251 >> null");//"учит" консоль русскому
    setlocale(LC_ALL, "Russian");
    cout << "\n\t\t~~~~~~~~~~Приветствуем вас в казино~~~~~~~~~\n\n";
    cout << "\n\nПожалуйста,введите ваше имя: ";
    string name;
    cin >> name;
    int bet, num, difficult, dice;//Рандомное число
    unsigned long long int balance;
    char choice;
    cout << "\n\nВведите баланс: $";
    cin >> balance;
    do
    {
        system("cls");
        cout << "Введите сложность\n";
        cin >> difficult;
        system("cls");
        rules();
        cout << "\n\n Ваш баланс: $ " << balance << "\n"; //Назначает баланс игрок
            do
            {

                cout << "Здравствуйте," << name << ",введите ставку: $";
                cin >> bet;
                if (bet > balance)
                    cout << "Введённая ставка не может привышать ваш баланс!Пожалуйста,повторите попытку!\n";
            } while (bet > balance);
            do
            {
                cout << "Введите число от 1 до 5 :";
                cin >> num;
                if (num <= 0 || num > 5)
                    cout << "\nЧисло должно быть от 1 до 5!Пожалуйста,повторите попытку!\n";
            } while (num <= 0 || num > 5);
            dice = rand() % 10 + 1;
            if (dice == num)
            {
                cout << "\n\nЛя ты везунчик!Ты заработал:" << bet * 2;
                balance = balance + bet * 2;
            }
            else
            {
                cout << "Прости,сегодня не твой день:( Ты потерял: $ " << bet << "\n";
                balance = balance - bet;
            }
            cout << "\n" << "Твой баланс состовляет: $ " << balance << "\n";
            if (balance == 0)
            {
                cout << "У тебя больше нет денег на игры";
                break;
            }

            cout << "\n\n-->Хочешь сыграть ещё?(y/n)<--\n";
            cin >> choice;
    } while (choice == 'y');
    cout << "\n\n\n";
    cout << "\n\nСпасибо тебе за игру,твой баланс: $ " << balance << "\n\n";
    return 0;
}