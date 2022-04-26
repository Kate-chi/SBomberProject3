#pragma once

#include <vector>
#include<typeinfo>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;

    //===========================================================

public:
    class BombIterator
    {
        std::vector<DynamicObject*>arr;
        int curIndex;
        DynamicObject* ptr;
    public:
        BombIterator(std::vector<DynamicObject*>ItArr) : arr(ItArr), curIndex(-1), ptr(nullptr)
        {
            ++(*this);
        }

        void resert() { curIndex = -1; ptr = nullptr; }

        BombIterator& operator++()
        {
            curIndex++;

            for (;curIndex < arr.size();curIndex++)
            {
                if (typeid (Bomb) == typeid(*(arr[curIndex])))
                {
                    ptr = arr[curIndex];
                    break;
                }
            }

            if (curIndex == arr.size())
            {
                curIndex = -1;
                ptr = nullptr;
            }

            return *this;
        }

        BombIterator& operator++(int)
        {
            auto temp = *this;
            ++(*this);
            return temp;
        }

        BombIterator& operator--()
        {
            for (;curIndex >= 0; curIndex--)
            {
                if (typeid(Bomb) == typeid(*(arr[curIndex])))
                {
                    ptr = arr[curIndex];
                    break;
                }
            }

            if (curIndex == -1)
            {
                ptr = nullptr;
            }

            return *this;
        }

        BombIterator& operator --(int)
        {
            auto temp = *this;
            --(*this);
            return temp;
        }

        DynamicObject*& operator*()
        {
            return arr.at(curIndex);
        }

        DynamicObject* operator->()
        {
            return ptr;
        }

        bool operator==(BombIterator it)
        {
            if (curIndex == it.curIndex &&
                ptr == it.ptr &&
                arr == it.arr)
            {
                return true;
            }
            return false;
        }

        bool operator!=(BombIterator it)
        {
            return!(*this == it);
        }
    };

    BombIterator begin() const
    {
        BombIterator it(vecDynamicObj);
        return it;
    }

    BombIterator end() const
    {
        BombIterator it(vecDynamicObj);
        it.resert();
        return it;
    }
};