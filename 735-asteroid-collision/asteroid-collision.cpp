#include <cmath>
#include <stack>
#include <vector>

class Solution {
public:
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> result;
        result.push_back(asteroids[0]);
        for(int i = 1; i<asteroids.size(); i++)
        {
            if(!result.empty())
            {
                int newAsteroid = asteroids[i];
                int oldAsteroid = result.back();

                if(newAsteroid > 0 && oldAsteroid > 0 || newAsteroid < 0 && oldAsteroid < 0) //both are moving in the same direction
                {
                    result.push_back(newAsteroid);
                }

                else if(newAsteroid > 0 && oldAsteroid < 0)
                { //moving away from each other
                    result.push_back(newAsteroid);
                }

                //moving towards each other
                else if(newAsteroid < 0 && oldAsteroid > 0)
                {
                    bool alive = true;

                    //the old asteroid destorys the new asteroid
                    if(abs(oldAsteroid) > abs(newAsteroid))
                    {
                        alive = false;
                        continue;
                    }

                    //the old asteroid and new get destoryed
                    else if(abs(oldAsteroid) == abs(newAsteroid))
                    {
                        alive = false;
                        result.pop_back();
                        continue;
                    }

                    //the new survivies
                    else if(abs(oldAsteroid)<abs(newAsteroid))
                    {
                        int current = result.back();
                        while(!result.empty() && current> 0 && (abs(current) < abs(newAsteroid)))
                        {
                            result.pop_back();
                            if(!result.empty())
                                current = result.back();
                        }
                    }

                    if(alive == false)
                    {
                        continue;
                    }
                    else
                    {
                        if(result.empty())
                        {
                            result.push_back(newAsteroid);
                        }
                        else
                        {
                            if(result.back() > 0 && result.back() > abs(newAsteroid)) 
                            {
                                continue;
                            }
                            else if(result.back() < 0)
                            {
                                result.push_back(newAsteroid);
                            }
                            else if(result.back() == abs(newAsteroid))
                            {
                                result.pop_back();
                            }
                        }
                    }
                }

            }
            else
            {
                result.push_back(asteroids[i]);

            }
        }
        return result;
    }
};