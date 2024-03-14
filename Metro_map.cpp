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
    Metro.addEdge("Rithala", "Rohini West", 1.9);
    Metro.addEdge("Rohini West", "Rohini East", 1.0);
    Metro.addEdge("Rohini East", "Pitam Pura", 1.5);
    Metro.addEdge("Pitam Pura", "Kohat Enclave", 1.0);
    Metro.addEdge("Kohat Enclave", "Netaji Subhash Place", 1.0);
    Metro.addEdge("Netaji Subhash Place", "Keshav Puram", 0.9);
    Metro.addEdge("Keshav Puram", "Kanhaiya Nagar", 1.1);
    Metro.addEdge("Kanhaiya Nagar", "Inderlok", 2.1);
    Metro.addEdge("Inderlok", "Shastri Nagar", 1.3);
    Metro.addEdge("Shastri Nagar", "Pratap Nagar", 1.4);
    Metro.addEdge("Pratap Nagar", "Pul Bangash", 1.1);
    Metro.addEdge("Pul Bangash", "Tis Hazari", 1.2);
    Metro.addEdge("Tis Hazari", "Kashmere Gate", 1.1);
    Metro.addEdge("Kashmere Gate", "Shastri Park", 1.0);
    Metro.addEdge("Shastri Park", "Seelampur", 1.3);
    Metro.addEdge("Seelampur", "Welcome", 2.1);
    Metro.addEdge("Welcome", "Shahdara", 2.1);
    Metro.addEdge("Shahdara", "Mansarovar Park", 1.0);
    Metro.addEdge("Mansarovar Park", "Jhilmil", 1.2);
    Metro.addEdge("Jhilmil", "Dilshad Garden", 1.0);
    Metro.addEdge("Dilshad Garden", "Shahid Nagar", 1.2);



    // Blue Line
    Metro.addEdge("Dwarka Sector 21", "Dwarka Sec 8", 2.0);
    Metro.addEdge("Dwarka Sec 8", "Dwarka Sec 9", 1.3);
    Metro.addEdge("Dwarka Sec 9", "Dwarka Sec 10", 1.4);
    Metro.addEdge("Dwarka Sec 10", "Dwarka Sec 11", 1.3);
    Metro.addEdge("Dwarka Sec 11", "Dwarka Sec 12", 0.7);
    Metro.addEdge("Dwarka Sec 12", "Dwarka Sec 13", 0.8);
    Metro.addEdge("Dwarka Sec 13", "Dwarka Sec 14", 1.1);
    Metro.addEdge("Dwarka Sec 14", "Dwarka", 1.0);
    Metro.addEdge("Dwarka", "Dwarka Mor", 1.0);
    Metro.addEdge("Dwarka Mor", "Nawada", 2.5);
    Metro.addEdge("Nawada", "Uttam Nagar West", 1.1);
    Metro.addEdge("Uttam Nagar West", "Uttam Nagar East", 1.2);
    Metro.addEdge("Uttam Nagar East", "Janak Puri West", 1.6);
    Metro.addEdge("Janak Puri West", "Janak Puri East", 1.2);
    Metro.addEdge("Janak Puri East", "Tilak Nagar", 1.1);
    Metro.addEdge("Tilak Nagar", "Subhash Nagar", 1.6);
    Metro.addEdge("Subhash Nagar", "Tagore Garden", 1.0);
    Metro.addEdge("Tagore Garden", "Rajouri Garden", 1.2);
    Metro.addEdge("Rajouri Garden", "Ramesh Nagar", 1.2);
    Metro.addEdge("Ramesh Nagar", "Moti Nagar", 1.0);
    Metro.addEdge("Moti Nagar", "Kirti Nagar", 1.4);
    Metro.addEdge("Kirti Nagar", "Shadipur", 1.3);
    Metro.addEdge("Shadipur", "Patel Nagar", 1.0);
    Metro.addEdge("Patel Nagar", "Rajendra Place", 1.3);
    Metro.addEdge("Rajendra Place", "Karol Bagh", 1.1);
    Metro.addEdge("Karol Bagh", "Jhandewalan", 1.0);
    Metro.addEdge("Jhandewalan", "R K Ashram Marg", 1.3);
    Metro.addEdge("R K Ashram Marg", "Rajiv Chowk", 1.0);
    Metro.addEdge("Rajiv Chowk", "Barakhamba Road", 0.9);
    Metro.addEdge("Barakhamba Road", "Mandi House", 0.8);
    Metro.addEdge("Mandi House", "Pragati Maidan", 0.8);
    Metro.addEdge("Pragati Maidan", "Indraprastha", 1.2);
    Metro.addEdge("Indraprastha", "Yamuna Bank", 1.6);
    Metro.addEdge("Yamuna Bank", "Akshardham", 1.0);
    Metro.addEdge("Akshardham", "Mayur Vihar Phase-1", 1.0);
    Metro.addEdge("Mayur Vihar Phase-1", "Mayur Vihar Extension", 1.0);
    Metro.addEdge("Mayur Vihar Extension", "New Ashok Nagar", 1.6);
    Metro.addEdge("New Ashok Nagar", "Noida Sec 15", 1.5);
    Metro.addEdge("Noida Sec 15", "Noida Sec 16", 0.8);
    Metro.addEdge("Noida Sec 16", "Noida Sec 18", 1.0);
    Metro.addEdge("Noida Sec 18", "Botanical Garden", 1.4);
    Metro.addEdge("Botanical Garden", "Golf Course", 1.3);
    Metro.addEdge("Golf Course", "Noida City Centre", 2.7);
    Metro.addEdge("Dwarka", "Najafgarh", 4.5);
    ///////////////////////// Vaishali Side //////////////////
    Metro.addEdge("Yamuna Bank", "Laxmi Nagar", 5.0);
    Metro.addEdge("Laxmi Nagar", "Nirman Vihar", 0.7);
    Metro.addEdge("Nirman Vihar", "Preet Vihar", 1.0);
    Metro.addEdge("Preet Vihar", "Karkarduma", 1.1);
    Metro.addEdge("Karkarduma", "Anand Vihar", 1.7);
    Metro.addEdge("Anand Vihar", "Kaushambi", 1.7);
    Metro.addEdge("Kaushambi", "Vaishali", 1.9);




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

    // Magenta Line
    Metro.addEdge("Botanical Garden", "Okhla Bird Sanctuary", 1.8);
    Metro.addEdge("Okhla Bird Sanctuary", "Kalindi Kunj", 1.4);
    Metro.addEdge("Kalindi Kunj", "Jasola Vihar Shaheen Bagh", 1.3);
    Metro.addEdge("Jasola Vihar Shaheen Bagh", "Okhla Vihar", 1.4);
    Metro.addEdge("Okhla Vihar", "Jamia Millia Islamia", 1.1);
    Metro.addEdge("Jamia Millia Islamia", "Sukhdev Vihar", 1.0);
    Metro.addEdge("Sukhdev Vihar", "Okhla NSIC", 1.2);
    Metro.addEdge("Okhla NSIC", "Kalkaji Mandir", 0.8);
    Metro.addEdge("Kalkaji Mandir", "Nehru Enclave", 1.2);
    Metro.addEdge("Nehru Enclave", "Greater Kailash", 1.3);
    Metro.addEdge("Greater Kailash", "Chirag Delhi", 1.4);
    Metro.addEdge("Chirag Delhi", "Panchsheel Park", 1.3);
    Metro.addEdge("Panchsheel Park", "Hauz Khas", 1.3);
    Metro.addEdge("Hauz Khas", "IIT Delhi", 2.5);
    Metro.addEdge("IIT Delhi", "R.K. Puram", 2.0);
    Metro.addEdge("R.K. Puram", "Munirka", 1.5);
    Metro.addEdge("Munirka", "Vasant Vihar", 2.1);
    Metro.addEdge("Vasant Vihar", "Shankar Vihar", 2.0);
    Metro.addEdge("Shankar Vihar", "IGI Airport Terminal 1", 1.9);
    Metro.addEdge("IGI Airport Terminal 1", "Sadar Bazar Cantonment", 2.4);
    Metro.addEdge("Sadar Bazar Cantonment", "Palam", 2.1);
    Metro.addEdge("Palam", "Dashrathpuri", 2.3);
    Metro.addEdge("Dashrathpuri", "Dabri Mor-Janakpuri South", 1.9);
    Metro.addEdge("Dabri Mor-Janakpuri South", "Janakpuri West", 1.2);

    //PInk Line

    Metro.addEdge("Majlis Park", "Azadpur", 5);
Metro.addEdge("Azadpur", "Shalimar Bagh", 3);
Metro.addEdge("Shalimar Bagh", "Netaji Subhash Place", 4);
Metro.addEdge("Netaji Subhash Place", "Shakurpur", 3);
Metro.addEdge("Shakurpur", "Punjabi Bagh West", 3);
Metro.addEdge("Punjabi Bagh West", "ESI Basaidarapur", 4);
Metro.addEdge("ESI Basaidarapur", "Rajouri Garden", 3);
Metro.addEdge("Rajouri Garden", "Mayapuri", 3);
Metro.addEdge("Mayapuri", "Naraina Vihar", 3);
Metro.addEdge("Naraina Vihar", "Delhi Cantonment", 3);
Metro.addEdge("Delhi Cantonment", "Durgabai Deshmukh South Campus", 3);
Metro.addEdge("Durgabai Deshmukh South Campus", "Sir Vishweshwaraiah Moti Bagh", 3);
Metro.addEdge("Sir Vishweshwaraiah Moti Bagh", "Bikaji Cama Place", 3);
Metro.addEdge("Bikaji Cama Place", "Sarojini Nagar", 3);
Metro.addEdge("Sarojini Nagar", "INA", 3);
Metro.addEdge("INA", "South Extension", 3);
Metro.addEdge("South Extension", "Lajpat Nagar", 3);
Metro.addEdge("Lajpat Nagar", "Vinobapuri", 3);
Metro.addEdge("Vinobapuri", "Ashram", 3);
Metro.addEdge("Ashram", "Hazrat Nizamuddin", 3);
Metro.addEdge("Hazrat Nizamuddin", "Mayur Vihar Phase-1", 3);
Metro.addEdge("Mayur Vihar Phase-1", "Mayur Vihar Pocket 1", 3);
Metro.addEdge("Mayur Vihar Pocket 1", "Trilokpuri Sanjay Lake", 3);
Metro.addEdge("Trilokpuri Sanjay Lake", "East Vinod Nagar", 3);
Metro.addEdge("East Vinod Nagar", "Mandawali-West Vinod Nagar", 3);
Metro.addEdge("Mandawali-West Vinod Nagar", "IP Extension", 3);
Metro.addEdge("IP Extension", "Anand Vihar", 3);
Metro.addEdge("Anand Vihar", "Karkarduma", 3);
Metro.addEdge("Karkarduma", "Karkarduma Court", 3);
Metro.addEdge("Karkarduma Court", "Krishna Nagar", 3);
Metro.addEdge("Krishna Nagar", "East Azad Nagar", 3);
Metro.addEdge("East Azad Nagar", "Welcome", 3);
Metro.addEdge("Welcome", "Maujpur-Babarpur", 3);
Metro.addEdge("Maujpur-Babarpur", "Gokulpuri", 3);
Metro.addEdge("Gokulpuri", "Johri Enclave", 3);
Metro.addEdge("Johri Enclave", "Shiv Nagar", 3);

// grey line
Metro.addEdge("Dwarka", "Nangli", 3.0);
Metro.addEdge("Nangli", "Najafgarh", 2.5);
Metro.addEdge("Najafgarh", "Dhansa Bus Stand", 2.0);

//orange line
Metro.addEdge("New Delhi", "Shivaji Stadium", 2.0);
Metro.addEdge("Shivaji Stadium", "Dhaula Kuan", 4.5);
Metro.addEdge("Dhaula Kuan", "Delhi Aerocity", 4.75);
Metro.addEdge("Delhi Aerocity", "IGI Airport", 3.0);
Metro.addEdge("IGI Airport", "Dwarka Sector 21", 3.0);

//Violet line
Metro.addEdge("Kashmere Gate", "Lal Qila", 3.0);
Metro.addEdge("Lal Qila", "Jama Masjid", 2.0);
Metro.addEdge("Jama Masjid", "Delhi Gate", 2.0);
Metro.addEdge("Delhi Gate", "ITO", 2.5);
Metro.addEdge("ITO", "Mandi House", 3.0);
Metro.addEdge("Mandi House", "Janpath", 2.5);
Metro.addEdge("Janpath", "Central Secretariat", 1.5);
Metro.addEdge("Central Secretariat", "Khan Market", 3.5);
Metro.addEdge("Khan Market", "Jawaharlal Nehru Stadium", 3.0);
Metro.addEdge("Jawaharlal Nehru Stadium", "Jangpura", 2.0);
Metro.addEdge("Jangpura", "Lajpat Nagar", 3.0);
Metro.addEdge("Lajpat Nagar", "Moolchand", 2.5);
Metro.addEdge("Moolchand", "Kailash Colony", 2.0);
Metro.addEdge("Kailash Colony", "Nehru Place", 2.5);
Metro.addEdge("Nehru Place", "Kalkaji Mandir", 2.0);
Metro.addEdge("Kalkaji Mandir", "Govind Puri", 2.0);
Metro.addEdge("Govind Puri", "Harkesh Nagar Okhla", 2.5);
Metro.addEdge("Harkesh Nagar Okhla", "Jasola Apollo", 2.5);
Metro.addEdge("Jasola Apollo", "Sarita Vihar", 2.5);
Metro.addEdge("Sarita Vihar", "Mohan Estate", 3.0);
Metro.addEdge("Mohan Estate", "Tughlakabad", 3.5);
Metro.addEdge("Tughlakabad", "Badarpur Border", 3.5);
Metro.addEdge("Badarpur Border", "Sarai", 2.0);
Metro.addEdge("Sarai", "NHPC Chowk", 3.0);
Metro.addEdge("NHPC Chowk", "Mewala Maharajpur", 3.5);
Metro.addEdge("Mewala Maharajpur", "Sector 28", 2.0);
Metro.addEdge("Sector 28", "Badkhal Mor", 2.0);
Metro.addEdge("Badkhal Mor", "Old Faridabad", 2.5);
Metro.addEdge("Old Faridabad", "Neelam Chowk Ajronda", 3.0);
Metro.addEdge("Neelam Chowk Ajronda", "Bata Chowk", 2.0);
Metro.addEdge("Bata Chowk", "Escorts Mujesar", 2.0);
Metro.addEdge("Escorts Mujesar", "Sant Surdas (Fermi)", 2.5);
Metro.addEdge("Sant Surdas (Fermi)", "Raja Nahar Singh", 3.0);






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
