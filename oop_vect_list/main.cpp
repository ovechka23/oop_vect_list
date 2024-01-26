#include <iostream>
#include <vector>
#include <list>
#include <chrono>
using namespace std;

void push_back(vector<long long> &v, long long &n, list<long long> &l)
{
    auto start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
        v.push_back(rand() % 10000);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "push_back vect " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
        l.push_back(v.at(i));
    end_time = chrono::high_resolution_clock::now();
    cout << "push_back list " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;

}

long long begin_to_end(vector<long long>& v, list<long long>& l)
{
    long long sum = 0;
    auto start_time = chrono::high_resolution_clock::now();
    for (vector<long long>::iterator i = v.begin(); i < v.end(); i++)
        sum += *i;
    auto end_time = chrono::high_resolution_clock::now();
    sum /= 500;
    cout << "begin to end vect " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    for (list<long long>::iterator i = l.begin(); i != l.end(); i++)
        sum += *i;
    end_time = chrono::high_resolution_clock::now();
    sum /= 500;
    cout << "begin to end list " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    return sum;
}

void clear(vector<long long>& v, list<long long>& l)
{
    auto start_time = chrono::high_resolution_clock::now();
    v.clear();
    auto end_time = chrono::high_resolution_clock::now();
    cout << "clear vect "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    l.clear();
    end_time = chrono::high_resolution_clock::now();
    cout << "clear list "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

void insert(vector<long long>& v, long long& n, list<long long>& l)
{
    auto start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
    {
       int r = rand() % (v.size()+1);
       auto st = v.begin();
       advance(st, r);
        v.insert(st, rand() % 10000);
    }
    auto end_time = chrono::high_resolution_clock::now();
    cout << "insert vect "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
    {
        auto st = l.begin();
        for (int k = 0; k < rand() % (v.size() + 1); k++)
            st++;
        l.insert(st, v.at(i));
    }
    end_time = chrono::high_resolution_clock::now();
    cout << "insert list "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

void print(vector<long long>& v)
{
    for (vector<long long>::iterator i = v.begin(); i < v.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void print(list<long long>& l)
{
    for (list<long long>::iterator i = l.begin(); i != l.end(); i++)
        cout << *i << " ";
    cout << endl;
}

void pop_back(vector<long long>& v, list<long long>& l)
{
    auto start_time = chrono::high_resolution_clock::now();
    while (v.size()!=0)
        v.pop_back();
    auto end_time = chrono::high_resolution_clock::now();
    cout << "pop_back vect "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    while (l.size()!=0)
        l.pop_back();
    end_time = chrono::high_resolution_clock::now();
    cout << "pop_back list "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

void erase(vector<long long>& v, list<long long>& l)
{
    auto start_time = chrono::high_resolution_clock::now();
    v.erase(v.begin(), v.end());
    auto end_time = chrono::high_resolution_clock::now();
    cout << "erase vect "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    l.erase(l.begin(), l.end());
    end_time = chrono::high_resolution_clock::now();
    cout << "erase list "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

void emplace(vector<long long>& v, long long &n, list<long long>& l)
{
    auto start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
        v.emplace(v.end(), rand() % 10000);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "emplase vect "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
    
    start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
        l.emplace(l.end(), v.at(i));
    end_time = chrono::high_resolution_clock::now();
    cout << "emplase list "<< chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

void push_front_insert(vector<long long>& v, list<long long>& l, long long &n)
{
    auto start_time = chrono::high_resolution_clock::now();
    for (long long i = 0; i < n; i++)
        v.insert(v.begin(), rand() % 10000);
    auto end_time = chrono::high_resolution_clock::now();
    cout << "push_front_insert vect " << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;

    start_time = chrono::high_resolution_clock::now();
    for (long long i = n-1; i >= 0; i--)
        l.push_front(v.at(i));
    end_time = chrono::high_resolution_clock::now();
    cout << "push_front_insert list " << chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << endl;
}

int main()
{
    vector<long long> vect1, vect2;
    list<long long> list1, list2;
    long long count=100000;
    double start_time, end_time;
    cout << count << endl;
    push_back(vect1, count, list1);
    /*for (long long i = 0; i < count; i++)
        vect2.push_back(vect1.at(i));
    for (long long i = 0; i < count; i++)
        list2.push_back(*next(list1.begin(), i));*/

    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);
        
    cout << begin_to_end(vect1, list1) << endl;
    
    clear(vect1, list1);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

    insert(vect1, count, list1);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

    pop_back(vect1, list1);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

   // push_front_insert(vect1, list1, count);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

    erase(vect1, list1);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

    emplace(vect1, count, list1);
    //print(vect1);
    //print(vect2);
    //print(list1);
    //print(list2);

    erase(vect1, list1);
    //erase(vect2, list2);

    system("pause");
    return 0;
}
//проход от begin до end
//push_back
//clear
//insert
//pop_back
//erase
//emplace
