
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
      if((logA[logA.size()-1]>='a')&&(logA[logA.size()-1]<='z'))
      {
         return true;
      }
      return false;  
   }

   string findContent(string &log)
   {
      int i=0;
      while(i<log.size()&&log[i]!=' ')
      {
         i++;
      }
      return log.substr(i);  
   }

   string findkey(string &log)
   {
     string key="";
     for(char &ch:log)
     {
        if(ch==' ')
        {
            break;
        }
        key+=ch;
     }
     return key;
   }

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLog;
        for(string &log:logs)
        {
            std::cout<<"log "<<log<<std::endl;
            if(isLetter(log))
            {
               letterLog.push_back(log);
            }
        }
#if 0
        std::string temp="dig1 8 1 5 1";
        string ContentA=findContent(temp);
        cout<<"ContentA "<<ContentA<<endl;

        string testTemp=findkey(temp);
        cout<<"testTemp"<<testTemp<<endl;
#else
    int counter=0;
    std::sort(letterLog.begin(),letterLog.end(),[&](string a,string b)
    {
        std::string contentA=findContent(a);
        std::string contentB=findContent(b);
        cout<<"counter "<<counter<<endl;
        cout<<"contentA "<<contentA<<endl;
        cout<<"contentB "<<contentB<<endl;
        counter++;

        // if(contentA==contentB)
        // {
        //     return findKey(a)>findkey(b)
        // }

        return true;
    }
    );

#endif
        return letterLog;
    }
};
