#include <set>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
    set<int> S;

    int i;
    set<int>::iterator j;

    cout << "请输入要排序的数字集合，一行一个。输入完成后，回车后按 Ctrl+D 结束输入：\n";

    while(cin >> i) {
        S.insert(i);
    }

    cout << "排序后的数字为：\n";

    for(j = S.begin(); j != S.end(); ++j) {
        cout << *j << "\n";
    }

    return 0;
}