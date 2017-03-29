#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct data
{
	int x=0,y=0,level=0;
};

int main (void){
	int width,length;
	cin >> length >> width ;

	bool a[length][width];
	bool visit[length][width];

	for(int s=0;s<length;s++)
		for(int t=0;t<width;t++)
			cin >> a[s][t];
	memset(visit, 0, sizeof(visit));

	data tmp;
	queue<data> YOLO;

	YOLO.push(tmp);
	while(!YOLO.empty()){
		tmp=YOLO.front();
		//boundry condition
		if(tmp.x<0||tmp.x>width-1||tmp.y<0||tmp.y>length-1){
			YOLO.pop();
			continue;
		}
		//collide or visit
		if(a[tmp.y][tmp.x]||visit[tmp.y][tmp.x]){
			YOLO.pop();
			continue;
		}
		//win
		if(tmp.x==width-1 && tmp.y==length-1){
			cout << tmp.level << endl;
			return 0;
		}
		visit[tmp.y][tmp.x] = 1;
		tmp.level++;
		YOLO.pop();
		//right
		tmp.x++;
		YOLO.push(tmp);
		tmp.x--;
		//down
		tmp.y++;
		YOLO.push(tmp);
		tmp.y--;
		//left
		tmp.x--;
		YOLO.push(tmp);
		tmp.x++;
		//up
		tmp.y--;
		YOLO.push(tmp);
		tmp.y++;
	}
	cout << "0" << endl;
	return 0;
}