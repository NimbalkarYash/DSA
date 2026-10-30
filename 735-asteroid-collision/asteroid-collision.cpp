#include <cmath>
#include <stack>
#include <vector>

class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;
        st.push(asteroids[0]);
        for(int i = 1; i<asteroids.size(); i++)
        {
            if(!st.empty())
            {
                int newAsteroid = asteroids[i];
                int oldAsteroid = st.top();

                if(newAsteroid > 0 && oldAsteroid > 0 || newAsteroid < 0 && oldAsteroid < 0) //both are moving in the same direction
                {
                    st.push(newAsteroid);
                }

                else if(newAsteroid > 0 && oldAsteroid < 0)
                {
                    st.push(newAsteroid);
                }

                else if(newAsteroid < 0 && oldAsteroid > 0)
                {
                    if(oldAsteroid < abs(newAsteroid))
                    {
                        bool bothDestroyed = false;
                        while(!st.empty()) //&& st.top() < abs(newAsteroid))
                        {
                            //st.pop();
                            if(st.top() > 0 && abs(st.top()) > abs(newAsteroid))
                            {
                                break;
                            }
                            else if(st.top() > 0 && abs(st.top()) < abs(newAsteroid))
                            {
                                st.pop();
                            }
                            else if(st.top()< 0)
                            {
                                break;
                            }
                            else if(st.top() > 0 && abs(st.top()) == abs(newAsteroid))
                            {
                                st.pop();
                                bothDestroyed = true;
                                break;
                            }
                        }
                        if (!bothDestroyed && (st.empty() || (!st.empty() && st.top() < 0)))
                        {
                            st.push(newAsteroid);
                        }

                        
                    }
                    else if(abs(oldAsteroid) == abs(newAsteroid))
                    {
                        st.pop();

                    }
                }

            }
            else
            {
                st.push(asteroids[i]);
            }
        }

        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};