#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<math.h>
#include<sstream>

#define IN "IN"
#define OUT "OUT"
using namespace std;

struct InOrOutTime {
    int hour;
    int minute;
};

struct Record {
    int carNum;
    InOrOutTime time;
    string inOrOut;
};

bool Cmp(Record& rec1, Record& rec2) {
    if (rec1.carNum == rec2.carNum)
        if (rec1.time.hour == rec2.time.hour)
            if (rec1.time.minute == rec2.time.minute) {
                if (rec1.inOrOut == IN)
                    return true;
                else
                    return false;
            }
            else
                return rec1.time.minute < rec2.time.minute;
        else
            return rec1.time.hour < rec2.time.hour;
    return rec1.carNum < rec2.carNum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<Record> recordTemp;
    map<int, int> carMap;
    for (int i = 0; i < records.size(); i++) {
        vector<string> stringTemp;
        istringstream iss(records[i]);
        string buffer;
        while (getline(iss, buffer, ' ')) {
            stringTemp.push_back(buffer);
        }
        int car = 0;
        for (int j = 0; j < 4; j++) {
            car *= 10;
            car += ((int)stringTemp[1][j] - 48);
        }
        int h = stoi(stringTemp[0].substr(0, 2));
        int m = stoi(stringTemp[0].substr(3, 2));
        InOrOutTime t = { h,m };
        Record rec = { car, t ,stringTemp[2] };
        recordTemp.push_back(rec);
        if (carMap.find(car) == carMap.end()) {
            carMap.insert({ car, 0 });
        }
    }
    sort(recordTemp.begin(), recordTemp.end(), Cmp);

    InOrOutTime timeTemp = {};
    for (int i = 0; i < recordTemp.size(); i++) {
        if (recordTemp[i].inOrOut == IN) {
            timeTemp = recordTemp[i].time;
            //마지막 IN의 기록은 있지만, OUT의 기록은 없을경우
            if ((i + 1 <= recordTemp.size() - 1 && recordTemp[i].carNum != recordTemp[i + 1].carNum)
                || i == recordTemp.size() - 1) {
                carMap[recordTemp[i].carNum] += 1439 -
                    (timeTemp.hour * 60 + timeTemp.minute);
                timeTemp = {  };
            }
        }
        else {
            carMap[recordTemp[i].carNum] += ((recordTemp[i].time.hour * 60 + recordTemp[i].time.minute) -
                (timeTemp.hour * 60 + timeTemp.minute));
        }
    }
    for (auto iter : carMap) {
        int don = fees[1];
        if (iter.second > fees[0]) {
            don += ceil((iter.second - fees[0]) / (double)fees[2]) * fees[3];
        }
        answer.push_back(don);
    }
    return answer;
}
