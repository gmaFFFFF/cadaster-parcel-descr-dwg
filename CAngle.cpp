//---------------------------------------------------------------------------
#pragma hdrstop
#include "CAngle.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
CAngle::CAngle(double gradus,bool sign)
{
    if(gradus < 0)
    {
        gradus *= -1;
        SetNewValue(gradus,0,0,false);
    }
    else
        SetNewValue(gradus,0,0,sign);
}
//---------------------------------------------------------------------------
CAngle::CAngle(double gradus,double minute,bool sign)
{
    if(gradus < 0)
    {
        gradus *= -1;
        SetNewValue(gradus,minute,0,false);
    }
    else
        SetNewValue(gradus,minute,0,sign);
}
//---------------------------------------------------------------------------
CAngle::CAngle(double gradus,double minute,double sec,bool sign)
{
    if(gradus < 0)
    {
        gradus *= -1;
        SetNewValue(gradus,minute,sec,false);
    }
    else
        SetNewValue(gradus,minute,sec,sign);
}
//---------------------------------------------------------------------------
CAngle::CAngle(AnsiString Value)
{
    SetNewValue(Value);
}
//---------------------------------------------------------------------------
void CAngle::SetNewValue(AnsiString Value)
{
    AnsiString Temp;
    double gradus,minute,sec;
    int count = 1;
    while(count <= Value.Length() && Value[count] != '°')
    {
        Temp += Value[count];
        count++;
    }
    if(Temp != "")
    {
        gradus = StrToFloat(Temp);
        if(gradus < 0 )
            gradus *= -1;
    }
    else
        gradus = 0;

    Temp = "";
    count++;
    while(count <= Value.Length() && Value[count] != '\'')
    {
        Temp += Value[count];
        count++;
    }
    if(Temp != "")
        minute = StrToFloat(Temp);
    else
        minute = 0;

    Temp = "";
    count++;
    while(count<=Value.Length() && Value[count] != '\"' && Value[count] != '\'')
    {
        Temp += Value[count];
        count++;
    }
    if(Temp != "")
        sec = StrToFloat(Temp);
    else
        sec = 0;

    if(Value[1] == '-')
        SetNewValue(gradus,minute,sec,false);
    else
        SetNewValue(gradus,minute,sec,true);
}

//---------------------------------------------------------------------------
void CAngle::SetNewValue(double gradus,double minute,double sec,bool sign)
{
    my_sign = sign;

    double temp;
    //floor(x):-округление вниз: наибольшее целое не большее x.
    my_gradus = abs(floor(gradus));

    temp = (gradus - GetGradus())*60 + minute;
    my_minute = abs(floor(temp));

    temp = (temp - GetMinute())*60 + sec;
    my_secund = abs(floor(temp + 0.0005));

    ReductionToFormatOfDegrees();
}
//---------------------------------------------------------------------------
void CAngle::ReductionToFormatOfDegrees()
{
    if(GetSecund() >= 60)
    {
        my_minute += GetSecund()/60;
        my_secund %= 60;
    }
    if(GetMinute() >= 60)
    {
        my_gradus += GetMinute()/60;
        my_minute %= 60;
    }
}
//---------------------------------------------------------------------------
double CAngle::GetRadian() const
{
    long double gradus;
    gradus = GetGradus()
                      + static_cast<long double>(GetMinute())/60
                      + static_cast<long double>(GetSecund())/3600;

    if(!IsPositiv())
        gradus *= -1;

    return DegToRad(gradus);

}
//---------------------------------------------------------------------------
AnsiString CAngle::GetValue(ANGLE_FORMAT form) const
{
    AnsiString Value;
    if(!IsPositiv())
    {
        Value += "-";
    }

    switch(form)
    {
    case af_FULL:
        Value += IntToStr(GetGradus()) + "°"
              +  IntToStr(GetMinute()) + "'"
              +  IntToStr(GetSecund()) + "\"";

        break;
    case af_TO_MINUTE:
        {
        float minute = GetMinute() + static_cast<float>(GetSecund())/60;

        Value += IntToStr(GetGradus()) + "°"
              +  FloatToStrF(minute,ffFixed,7,1) + "\'";
        }
        break;

    case af_TO_GRADUS:
        {
        float gradus = GetGradus()
                     + static_cast<float>(GetMinute())/60
                     + static_cast<float>(GetSecund())/3600;

        Value += FloatToStrF(gradus,ffFixed,7,2) + "°";
        }
        break;

    case af_RADIAN:
        {
        long double degress_in_radian = GetRadian();

        Value += FloatToStrF(degress_in_radian,ffFixed,17,16);
        }
        break;

    default:
        return Value;
    }
    return Value;
}
//---------------------------------------------------------------------------
CAngle::operator double() const
{
    double gradus = GetGradus()
                  + static_cast<double>(GetMinute())/60
                  + static_cast<double>(GetSecund())/3600;

    return IsPositiv()?gradus:gradus * -1;
}
//---------------------------------------------------------------------------
bool CAngle::operator == (const CAngle& rhs) const
{
    if(IsPositiv() != rhs.IsPositiv())
        return false;
    if(GetGradus() != rhs.GetGradus())
        return false;
    if(GetMinute() != rhs.GetMinute())
        return false;
    if(GetSecund() != rhs.GetSecund())
        return false;
    return true;
}
//---------------------------------------------------------------------------
bool CAngle::operator != (const CAngle& rhs) const
{
    return (*this == rhs) ? false : true;
}
//---------------------------------------------------------------------------
bool CAngle::operator > (const CAngle& rhs) const
{
    if(double(*this) > double(rhs))
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------
bool CAngle::operator < (const CAngle& rhs) const
{
    if(double(*this) < double(rhs))
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------
bool CAngle::operator >= (const CAngle& rhs) const
{
    if(double(*this) >= double(rhs))
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------
bool CAngle::operator <= (const CAngle& rhs) const
{
    if(double(*this) <= double(rhs))
        return true;
    else
        return false;
}
//---------------------------------------------------------------------------
CAngle CAngle::operator + (const CAngle& rhs) const
{
    double result = double(*this) + double(rhs);
    if(result < 0)
        return CAngle(result,0,0,false);
    return CAngle(result);
}
//---------------------------------------------------------------------------
CAngle CAngle::operator - (const CAngle& rhs) const
{
    double result = double(*this) - double(rhs);
    if(result < 0)
        return CAngle(result,0,0,false);
    return CAngle(result);
}
//---------------------------------------------------------------------------
CAngle CAngle::operator * (double x) const
{
    return CAngle(double(*this) * x);
}
//---------------------------------------------------------------------------
CAngle CAngle::operator / (double x) const
{
    return CAngle(double(*this) / x);
}
//---------------------------------------------------------------------------
AnsiString CAngle::GetRumb(ANGLE_FORMAT format) const
{
    AnsiString Rumb;
    CAngle Temp(*this);

    while(Temp >= CAngle(360))
        Temp = Temp - CAngle(360);
    while(Temp < CAngle(0))
        Temp = Temp + CAngle(360);

    if(Temp == CAngle(0))
    {
        Rumb = "Север ";
        return Rumb;
    }
    if(Temp == CAngle(90))
    {
        Rumb = "Восток ";
        return Rumb;
    }
    if(Temp == CAngle(180))
    {
        Rumb = "Юг ";
        return Rumb;
    }
    if(Temp == CAngle(270))
    {
        Rumb = "Запад ";
        return Rumb;
    }


    if(Temp > CAngle(0) && Temp < CAngle(90))
    {
        Rumb = "СВ: " + Temp.GetValue(format);
        return Rumb;
    }
    if(Temp > CAngle(90) && Temp < CAngle(180))
    {
        Temp = CAngle(180) - Temp;
        Rumb = "ЮВ: " + Temp.GetValue(format);
        return Rumb;
    }
    if(Temp > CAngle(180) && Temp < CAngle(270))
    {
        Temp = Temp - CAngle(180);
        Rumb = "ЮЗ: " + Temp.GetValue(format);
        return Rumb;
    }
    else
    {
        Temp = CAngle(360) - Temp;
        Rumb = "СЗ: " + Temp.GetValue(format);
    }
    return Rumb;
}
//---------------------------------------------------------------------------
void CAngle::ReductionAngleToGeodFormat()
{
    while(*this >= CAngle(360))
        *this = *this - CAngle(360);
    while(*this < CAngle(0))
        *this = *this + CAngle(360);
}
//---------------------------------------------------------------------------
CAngle StrToAngle(const AnsiString& Value)
{
    bool gradus = false;
    bool min = false;
    bool sec = false;
    AnsiString Val("");

    Set<char, '0','9'> Dig;
    Dig << '0' << '1' << '2' << '3' << '4' << '5' << '6' << '7' << '8' << '9';

    //Находим все символы, не цифры, в ячейке и превращаём их в значки градусов,
    //а цифры оставляем как есть.
    for(int i = 1; i <= Value.Length() ; i++)
    {
        if(gradus == true && min == true && sec == true)
            break;

        if((Value[i] == '+' || Value[i] == '-') && i == 1)
        {
            Val += Value[i];
            continue;
        }

        if(Value[i] == '.' || Value[i] == ',')
        {
            Val += ',';
            continue;
        }

        if(!Dig.Contains(Value[i]))
        {
            if(gradus == false)
            {
                Val += '°';
                gradus = true;
                continue;
            }
            else if(min == false)
            {
                Val += '\'';
                min = true;
                continue;
            }
            else if(sec == false)
            {
                Val += '\"';
                sec = true;
                continue;
            }
        }
        else
        {
            Val += Value[i];
            continue;
        }
    }
    return CAngle(Val);
}
//---------------------------------------------------------------------------
