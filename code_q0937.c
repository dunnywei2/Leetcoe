
->link with youtube->https://www.youtube.com/watch?v=UbNU98fKV8o

  ->second one->https://www.youtube.com/watch?v=JRm0ybcPSFc



  /*Other C++ soluction*/
  class Solution {
private:
    string findKey(string &log) {
        int i = 0;
        string key = "";
        for(char &ch: log) {
            if(ch == ' ')
                break;
            key += ch;
        }
        return key;
    }
    string findContent(string &log) {
        int i = 0;
        while(i < log.size() && log[i] != ' ')
            i++;
        
        return log.substr(i);
    }
    bool isLetterLog(string &log) {
        return log[log.size() - 1] >= 'a' 
                && log[log.size() - 1] <= 'z';
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs;
        // O(N)
        for(string &log: logs) {
            if(isLetterLog(log)) 
                letterLogs.push_back(log);
        }
            
        // O(NLogN ∗ L)
        sort(letterLogs.begin(), letterLogs.end(),
        [&](string &a, string &b) {
            string contentA = findContent(a);
            string contentB = findContent(b);
            if(contentA == contentB) 
                return findKey(a) < findKey(b);
            else 
                return contentA < contentB;
        });

        // O(N)
        vector<string> res;
        for(string &letterLog: letterLogs) 
            res.push_back(letterLog);
        
        // O(N)
        for(string &log: logs) {
            if(!isLetterLog(log))
                res.push_back(log);
        }

        return res;

    }
};

---------------my C++ solution--------------
  class Solution {
private:
   bool isLetter(string &logA)
   {
    //   int size=logA.size()-1;
#if 1
    //   if(logA[size]>='a')
    if((logA[logA.size()-1]>='a')&&(logA[logA.size()-1]>='z'))
    {
        std::cout<<"TRUE"<<std::endl;
         return true;
    }
#endif
      std::cout<<"FALSE"<<std::endl;
      return false;
   }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLog;
        for(string &log:logs)
        {
            std::cout<<"log"<<log<<std::endl;
            isLetter(log);
        }
        return letterLog;
    }
};
