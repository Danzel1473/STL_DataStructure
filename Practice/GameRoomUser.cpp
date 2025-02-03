#include "GameRoomUser.h"
#include "iostream"

const int maxCount = 6;

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    if (IsEmpty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    if (!IsFull())
    {
        users.emplace_back(userInfo);
        return true;
    }

    std::cout << "방이 가득 차서 " << userInfo.userName << "이 입장하지 못함\n";
    return false;

}

bool GameRoomUser::DeleteUser(const char* userName)
{
    auto it = users.begin();
    for (; it != users.end(); ++it)
    {
        if (it->userName == userName)
        {
            break;
        }
    }
    if (it == users.end())
        return false;

    users.erase(it);
    if (it == users.begin())
    {
        masterUserName = users[0].userName;
    }
    return true;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() >= maxCount;
}

UserInfo& GameRoomUser::GetUserOfName(const char* userName)
{
    for (int i = 0; i < users.size(); ++i)
    {
        if (users[i].userName == userName)
            return users[i];
    }
    std::cout << "찾지못함" << "\n";
}

UserInfo& GameRoomUser::GetMasterUser()
{
    for (int i = 0; i < users.size(); ++i)
    {
        if (users[i].userName == masterUserName)
            return users[i];
    }
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    return users[users.size() - 1];
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.size() < orderNum)
        return false;
    
    auto it = users.begin() + (orderNum - 1);
    users.erase(it);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
    }
    return true;
}

void GameRoomUser::Clear()
{
    users.clear();
}
