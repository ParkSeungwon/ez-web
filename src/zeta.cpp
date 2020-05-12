#include<fstream>
#include"tcpip/server.h"
#include"tcpip/bootstrap.h"
using namespace std;

class MyWeb : public BootStrapSite
{
protected:
	string language = "korean";
	void process() {
		if(requested_document_ == "index.html") {
			ifstream f("carousel.txt");
			int n; string s; vector<string> v[3];
			f >> n; getline(f, s);
			for(int i=0; i<n; i++) for(int j=0; j<3; j++) {
				getline(f, s);
				v[j].push_back(s);
			}
			swap("@CAROUSEL", carousel(v[0], v[1], v[2]));
		} else if(requested_document_ == "result_view") {
			if(!nameNvalue_.empty()) {
				content_ = "<html><h2>";
				for(auto [a, b] : nameNvalue_) content_ += a + ':' + b + "<br>";
				content_ += "</h2></html>";
			}
		} else if(requested_document_ == "korean") language = "korean";
		else if(requested_document_ == "english") language = "english";
		else if(requested_document_ == "tutorial.js") if(language == "korean") swap("kor", "eng");
	}
};

int main(int ac, char **av)
{
	MyWeb f;
	f.init(av[1]);
	Server sv{atoi(av[2])};
	sv.start(f);
}

