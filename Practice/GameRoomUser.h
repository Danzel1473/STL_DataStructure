#include <vector>
#include <string>

using namespace std;

// 유저 정보
struct UserInfo
{
	UserInfo()
	{
	}

	UserInfo(string userName, int level, int exp)
		:userName(userName), level(level), exp(exp)
	{
	}

	string userName; // 이름
	int level; // 레벨
	int exp; // 경험치
};

// 게임 방의 유저를 관리하는 클래스
// 방에는 최대 6명까지 들어 갈 수 있다.
// 방에 들어 오는 순서 중 가장 먼저 들어 온 사람이 방장이 된다.
class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

	// 방에 유저 추가
	bool AddUser(UserInfo& userInfo);

	// 방에서 유저 삭제.
	// 만약 방장이 나가면 userName에 새로운 방장의 이름을 설정 해야 된다.
	bool DeleteUser(const char* userName);

	// 방에 유저가 없는지 확인. 없으면 true 반환
	bool IsEmpty();

	// 방에 유저가 꽉 찼는지 확인. 꽉 찼다면 true 반환
	bool IsFull();

	// 특정 유저의 정보
	UserInfo& GetUserOfName(const char* userName);

	// 방장의 유저 정보
	UserInfo& GetMasterUser();

	// 가장 마지막에 방에 들어 온 유저의 정보
	UserInfo& GetUserOfLastOrder();

	// 특정 순서에 들어 온 유저를 쫒아낸다.
	bool BanUser(int orderNum);

	// 모든 유저를 삭제한다.
	void Clear();

private:
	vector<UserInfo> users;
	string masterUserName; // 방장의 이름
};