struct Node{
	int x;
};
bool operator<(const Node& a,const Node &b){
	return a.x>b.x;
}
