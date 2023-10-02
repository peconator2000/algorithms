#include <iostream>
using namespace std;



int main(void)
{
    int students_num, variants_num, row_, place, petya_place, row_back, row_front;
    std::cin>>students_num;
    std::cin>>variants_num;
    std::cin>>row_;
    std::cin>>place;
    petya_place = (row_ - 1) * 2 + place;
    if (petya_place > students_num)
        cout<<"-1";
    else
    {
        row_back = -1;
        row_front = -1;
        if (petya_place + variants_num <= students_num)
            row_back = ((petya_place + variants_num - ((petya_place + variants_num) % 2 == 0 ? 2 : 1))/2 + 1);
        if (petya_place - variants_num > 0)
            row_front = ((petya_place - variants_num - ((petya_place - variants_num) % 2 == 0 ? 2 : 1))/2 + 1);
        if (row_front == -1 && row_back == -1)
            cout << -1;
        else if (row_front == -1)
            cout<<row_back<<" "<<((petya_place + variants_num) % 2 == 0 ? 2 : 1);
        else if (row_back == -1)
            cout<<row_front<<" "<<((petya_place - variants_num) % 2 == 0 ? 2 : 1);
        else
            cout<<((row_ - row_front < row_back - row_) ? row_front:row_back)<< " " <<((petya_place + variants_num) % 2 == 0 ? 2 : 1);     

    }
    return (0);
}

