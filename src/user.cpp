#include "pch.h"
#include "user.h"
#include"MD5.h"
#include"testLegal.h"
#include <string>

using std::string;

user::user(const CString& name, const CString& pasword, PGconn* con)
{
    CStringA n_ame(name);
    CStringA p_asword(pasword);
    string na(n_ame.GetBuffer());
    string pa(p_asword.GetBuffer());
    username = na;
    password = pa;
    conn = con;
    n_ame.ReleaseBuffer();
    p_asword.ReleaseBuffer();
}


bool user::isSuperUser()
{
    if (username == "admin")
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
    //if using on other database, use the code below;
    
    /*std::string sqlop = "select * from super_user where sname = '" + username + "'";

    PGresult* res = PQexec(conn, sqlop.c_str());
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {

        PQclear(res);
        return false;
    }
    else
    {
        if (PQntuples(res) == 0)
        {
            PQclear(res);
            return false;
        }
        else
        {
            PQclear(res);
            return true;
        }
    }*/
}

int user::login()
{
    string tablen;
    if (!isValidInput(username) || !isValidInput(password))
    {
        return 4;
    }

    if (isSuperUser())
        tablen = "super_user";
    else
        tablen = "common_user";

    string sql = "select * from " + tablen + " where sname = '" + username + "'";
    PGresult* res = PQexec(conn, sql.c_str());
    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        PQclear(res);
        return 1;
    }
    else
    {
        if (PQntuples(res) == 0)
        {
            PQclear(res);
            return 2;
        }
        else
        {
            string md5_password = PQgetvalue(res, 0, 4);
            MD5 test;
            if (md5_password == test.encode(password))
            {
                PQclear(res);
                return 0;
            }
            else
            {
                PQclear(res);
                return 3;
            }
        }
    }
}


