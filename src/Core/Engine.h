#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
public:
    static Engine *GetInstance()
    {
        if (m_instance == nullptr)
        {
            m_instance = new Engine();
        }
        return m_instance;
    }

    void Init();
    void Clean();
    void Quit();

    void Update(float dt);
    void Render();
    void Events();   

    inline bool IsRunning() { return m_isRunning; }

private:
    Engine(){};
    bool m_isRunning = false;
    static Engine *m_instance;
};

#endif