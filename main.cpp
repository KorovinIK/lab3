#include <iostream>
#include <vector>
using namespace std;


vector<double> input_numbers(size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

int main()
{
    //ввод
    size_t number_count;
    cerr << "Enter number count ";
    cin >> number_count;

    vector<double> numbers(number_count);
    cerr << "Enter numbers ";
    vector<double> numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter bin count ";
    cin >> bin_count;
    //расчет гистограммы
    double min = numbers[0];
    double max = numbers[0];
    for (double number : numbers){
        if (min > number){
            min = number;}
        if (max < number){
            max = number;}
    }
    vector<size_t> bins(bin_count,0);
    double bin_size = (max-min)/bin_count;
    for (size_t i=0;i<number_count;i++)
    {
        bool found = false;
        for (size_t j=0;j<(bin_count - 1) && !found;j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j+1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi)){
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }
    //вывод гистограммы
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
    size_t max_bin = bins[0];
    for (size_t bin : bins){
        if (max_bin < bin){
            max_bin = bin;}
    }
    bool prov = false;
    if (max_bin > MAX_ASTERISK){
        prov = true;
    }
    vector<size_t> binsh(bin_count,0);
    for(size_t i=0; i<bin_count; i++ ){
        size_t height = bins[i];
        if (prov == true){
            height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_bin);
            binsh[i] = height;
        }
        else{
            binsh[i] = bins[i];
        }
    }
    for(size_t i=0; i<bin_count; i++ ){
        if (bins[i] < 100){
            cout << ' ';}
        if (bins[i] < 10){
            cout << ' ';}
	    cout << bins[i] << "|";
        for (size_t j=0; j<binsh[i]; j++){
            if((j == binsh[i-1]-1) && (binsh[i-1] != binsh[i+1])   ){cout << "^";}
            else if((j == binsh[i+1]-1) && (binsh[i-1] != binsh[i+1])   ){cout << "v";}
            else if((j == binsh[i+1]-1) && (binsh[i-1] == binsh[i+1])   ){cout << "N";}
            else{cout  << "*";}
        }
        cout << endl;
    }
    return 0;
}
