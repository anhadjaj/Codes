#include<iostream>
#include<list>
#include<unordered_map>
#include<set>
#include<queue>
using namespace std;
template<typename T>

class graph{
    public:
    unordered_map<T, list<T> >  h;

    void addEdge(T u, T v, bool bi)
    {
        h[u].push_back(v);
        if(bi)
        {
            h[v].push_back(u);
        }
    }

    void print_g()
    {
        for(auto x: h)
        {
            cout<< x.first<<"->";
            for(auto y: x.second)
            {
                cout<< y<<", ";
            }
            cout<< endl;
        }
    }

    void bfs(string src, T fin)
    {
        queue<string>q;
        q.push(src);
        unordered_map<T, bool> visited;
        unordered_map<T, int> dis;
        unordered_map<T,T> parent;
        dis[src] = 0;
        visited[src] = true;

        while(!q.empty())
        {
            T x = q.front();
            q.pop();
            // cout<< x<<" ";
            for (auto p : h[x])
            {
                if(!visited[p])
                {
                    q.push(p);
                    dis[p] = dis[x] + 1;
                    visited[p] = true;
                    parent[p] = x;
                }
            }
        }
        T l = fin;
        while(l!= src)
        {
            cout<< l<<"<=";
            l = parent[l];
        }
        cout<< src<<endl;
    }

    void dfs(T src, T dest, unordered_map<T, bool> &visited, vector<T> &path, int& i) {
        visited[src] = true;
        path.push_back(src);

        if (src == dest) {
            cout<< "("<< i<<"). ";
            for (auto node : path) {
                cout << node << "-->";
            }
            i++;
            cout << endl;
            cout<< endl;
            cout<< endl;
        }
        else {
            for (auto x : h[src]) {
                if (!visited[x]) {
                    dfs(x, dest, visited, path, i);
                }
            }
        }

        visited[src] = false;
        path.pop_back();
    }
};

int main()
{
    graph<string> Metro;
        // Red Line
    Metro.addEdge("Rithala", "Netaji Subhash Place", 9.3);
    Metro.addEdge("Netaji Subhash Place", "Keshav Puram", 2.1);
    Metro.addEdge("Keshav Puram", "Kanhaiya Nagar", 1.4);
    Metro.addEdge("Kanhaiya Nagar", "Inderlok", 2.1);
    Metro.addEdge("Inderlok", "Shastri Nagar", 2.1);
    Metro.addEdge("Shastri Nagar", "Pratap Nagar", 3.0);
    Metro.addEdge("Pratap Nagar", "Pulbangash", 1.4);
    Metro.addEdge("Pulbangash", "Tis Hazari", 1.6);
    Metro.addEdge("Tis Hazari", "Kashmere Gate", 2.0);
    Metro.addEdge("Kashmere Gate", "Shastri Park", 4.0);
    Metro.addEdge("Shastri Park", "Seelampur", 2.9);
    Metro.addEdge("Seelampur", "Welcome", 2.0);

    // Blue Line
    Metro.addEdge("Rajouri Garden", "Ramesh Nagar", 1.3);
    Metro.addEdge("Ramesh Nagar", "Moti Nagar", 1.6);
    Metro.addEdge("Moti Nagar", "Kirti Nagar", 1.3);
    Metro.addEdge("Kirti Nagar", "Shadipur", 0.9);
    Metro.addEdge("Shadipur", "Patel Nagar", 1.9);
    Metro.addEdge("Patel Nagar", "Rajender Place", 1.3);
    Metro.addEdge("Rajender Place", "Karol Bagh", 1.5);
    Metro.addEdge("Karol Bagh", "Rajiv Chowk", 4.0);
    Metro.addEdge("Rajiv Chowk", "Barakhamba Road", 0.8);
    Metro.addEdge("Barakhamba Road", "Mandi House", 1.3);
    Metro.addEdge("Mandi House", "Supreme Court", 1.0);
    Metro.addEdge("Supreme Court", "Inderprastha", 1.0);
    Metro.addEdge("Inderprastha", "Yamuna Bank", 2.3);
    Metro.addEdge("Yamuna Bank", "Laxmi Nagar", 1.6);
    Metro.addEdge("Laxmi Nagar", "Nirman Vihar", 1.3);
    Metro.addEdge("Nirman Vihar", "Preet Vihar", 1.2);
    Metro.addEdge("Preet Vihar", "Karkar Duma", 1.5);
    Metro.addEdge("Karkar Duma", "Anand Vihar", 1.3);
    Metro.addEdge("Anand Vihar", "Kaushambi", 1.0);
    Metro.addEdge("Kaushambi", "Vaishali", 2.0);
    Metro.addEdge("Yamuna Bank", "Akshardham", 1.6);
    Metro.addEdge("Akshardham", "Mayur Vihar Phase-1", 2.3);
    Metro.addEdge("Mayur Vihar Phase-1", "Mayur Vihar Extention", 1.5);
    Metro.addEdge("Mayur Vihar Extention", "New Ashok Nagar", 1.1);
    Metro.addEdge("New Ashok Nagar", "Noida Sector-15", 1.2);
    Metro.addEdge("Noida Sector-15", "Noida Sector-16", 1.3);
    Metro.addEdge("Noida Sector-16", "Noida Sector-18", 1.3);
    Metro.addEdge("Noida Sector-18", "Botanical Garden", 1.3);
    Metro.addEdge("Botanical Garden", "Golf Course", 1.4);
    Metro.addEdge("Golf Course", "Noida City Center", 1.5);

    // Green Line
    Metro.addEdge("Madipur", "Shivaji Park", 1.4);
    Metro.addEdge("Shivaji Park", "Punjabi Bagh", 2.0);
    Metro.addEdge("Punjabi Bagh", "Ashok Park", 1.1);
    Metro.addEdge("Ashok Park", "Inderlok", 1.7);
    Metro.addEdge("Ashok Park", "Sant Guru Ram Singh Marg", 1.4);
    Metro.addEdge("Sant Guru Ram Singh Marg", "Kirti Nagar", 1.3);
    Metro.addEdge("Kashmere Gate", "Lal Qila", 2.0);
    Metro.addEdge("Lal Qila", "Jama Masjid", 1.0);
    Metro.addEdge("Jama Masjid", "Delhi Gate", 1.7);
    Metro.addEdge("Delhi Gate", "ITO", 1.6);
    Metro.addEdge("ITO", "Mandi House", 1.0);
    Metro.addEdge("Mandi House", "Janptah", 1.7);
    Metro.addEdge("Janptah", "Central Secretariat", 1.6);
    Metro.addEdge("Central Secretariat", "Khan Market", 2.6);
    Metro.addEdge("Khan Market", "JL Nehru Stadium", 1.7);
    Metro.addEdge("JL Nehru Stadium", "Jangpura", 1.1);

    // Yellow Line
    Metro.addEdge("Vishwavidyalaya", "Vidhan Sabha", 1.3);
    Metro.addEdge("Vidhan Sabha", "Civil Lines", 1.7);
    Metro.addEdge("Civil Lines", "Kashmere Gate", 1.4);
    Metro.addEdge("Kashmere Gate", "Chandni Chowk", 1.4);
    Metro.addEdge("Chandni Chowk", "Chawri Bazar", 1.3);
    Metro.addEdge("Chawri Bazar", "New Delhi", 1.0);
    Metro.addEdge("New Delhi", "Rajiv Chowk", 1.4);
    Metro.addEdge("Rajiv Chowk", "Patel Chowk", 1.6);
    Metro.addEdge("Patel Chowk", "Central Secretariat", 1.1);
    Metro.addEdge("Central Secretariat", "Udyog Bhawan", 0.4);
    Metro.addEdge("Udyog Bhawan", "Lok Kalyan Marg", 2.0);
    Metro.addEdge("Lok Kalyan Marg", "Jor Bagh", 1.5);
    Metro.addEdge("Samaypur Badli", "Rohini Sector - 18", 1.1);
    Metro.addEdge("Rohini Sector - 18", "Haiderpur Badli Mor", 1.9);
    Metro.addEdge("Haiderpur Badli Mor", "Jahangirpuri", 1.9);
    Metro.addEdge("Jahangirpuri", "Adarsh Nagar", 1.9);
    Metro.addEdge("Adarsh Nagar", "Azadpur", 2.1);
    Metro.addEdge("Azadpur", "Model Town", 2.0);
    Metro.addEdge("Model Town", "GTB Nagar", 2.0);
    Metro.addEdge("GTB Nagar", "Vishwavidyalaya", 1.2);
    Metro.addEdge("Jor Bagh", "INA", 1.9);
    Metro.addEdge("INA", "AIIMS", 1.2);
    Metro.addEdge("AIIMS", "Green Park", 1.5);
    Metro.addEdge("Green Park", "Hauz Khas", 2.6);
    Metro.addEdge("Hauz Khas", "Malviya Nagar", 2.4);
    Metro.addEdge("Malviya Nagar", "Saket", 1.3);
    Metro.addEdge("Saket", "Qutab Minar", 2.4);
    Metro.addEdge("Qutab Minar", "Chhattarpur", 1.8);
    Metro.addEdge("Chhattarpur", "Sultanpur", 2.1);
    Metro.addEdge("Sultanpur", "Ghitorni", 1.8);
    Metro.addEdge("Ghitorni", "Arjan Garh", 3.6);
    Metro.addEdge("Arjan Garh", "Guru Dronacharya", 3.1);
    Metro.addEdge("Guru Dronacharya", "Sikandarpur", 1.4);
    Metro.addEdge("Sikandarpur", "MG Road", 1.7);
    Metro.addEdge("MG Road", "IFFCO Chowk", 1.6);
    Metro.addEdge("IFFCO Chowk", "Huda City Centre", 2.0);


    string src;
    cout<<"Enter the starting station: ";
    getline(cin, src);

    string dest;
    cout<< "Enter the destination here: ";
    getline(cin, dest);
    cout<< endl;
    cout<< endl;

    cout<<"1. Provide all the possible paths."<<endl;
    cout<< "2. Provide the shortest possible path."<<endl;

    cout<< "Enter your preference: ";

    int display;
    cin>> display;
    if(display == 1)
    {
        int i= 1;
        unordered_map<string, bool> visited;
        vector<string> path;
        Metro.dfs(src, dest, visited, path, i);
    }
    else if(display == 2){
        Metro.bfs(src, dest);
    }

    return 0;
}