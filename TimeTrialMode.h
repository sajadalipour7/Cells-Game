#ifndef TIMETRIALMODE_H_INCLUDED
#define TIMETRIALMODE_H_INCLUDED
int GetSeconds()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int S=tm.tm_sec;
    return S;
}
int GetMinutes()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int S=tm.tm_min;
    return S;
}
int GetHours()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int S=tm.tm_hour;
    return S;
}
int TimeConvertor(char x,int h,int m,int s,int t)
{
    s+=t;
    if(s>=60)
    {
        m+=(int)(s/60);
        s=s%60;
    }
    if(m>=60)
    {
        h+=(int)(m/60);
        m=m%60;
    }
    if(h>=24)
    {
        h=h%24;
    }
    switch (x)
    {
    case 'h':
        return h;
        break;
    case 'm':
        return m;
        break;
    case 's':
        return s;
        break;
    }
    return -1;
}
long long int GetTimePast()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    long long int TimePast=tm.tm_hour*3600+tm.tm_min*60+tm.tm_sec;
    return TimePast;
}


#endif // TIMETRIALMODE_H_INCLUDED
