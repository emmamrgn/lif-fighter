#include "CharacterState.h"


CharacterState::CharacterState(){}

CharacterState::~CharacterState(){}

string CharacterState::GetStateString(States state)
{
    switch(state)
    {
    case States::IDLE: 
       return "idle";
       break;
    case States::WALK: 
        return "walk"; 
        break;
    case States::WALKBACK: 
        return "walkback"; 
        break;
    case States::CROUCH: 
        return "crouch"; 
        break;
    case States::JUMP: 
        return "jump"; 
        break;
    case States::PUNCH: 
        return "punch"; 
        break;
    case States::KICK: 
        return "kick"; 
        break;
    case States::HIT: 
        return "hit"; 
        break;
    case States::START: 
        return "start"; 
        break;
    case States::LOSER: 
        return "loser"; 
        break;
    case States::WINNER: 
        return "winner"; 
        break;
    default: break;
    }
    return "aucune action";
}

string CharacterState::GetCurrentStateString()
{
    return GetStateString(state);
}

void CharacterState::SetIdle()
{
    if(state == States::IDLE)
    {
        return; 
    } 
    state = States::IDLE;
    ResetFrames = true;
}

void CharacterState::SetWalk()
{
    if(state == States::WALK)
    {
        return; 
    } 
    state = States::WALK;
    ResetFrames = true;
}

void CharacterState::SetWalkback()
{
    if(state == States::WALKBACK)
    {
        return; 
    } 
    state = States::WALKBACK;
    ResetFrames = true;
}

void CharacterState::SetKick()
{
    if(state == States::KICK)
    {
        return; 
    } 
    state = States::KICK;
    ResetFrames = true;
}


void CharacterState::SetPunch()
{
    if(state == States::PUNCH)
    {
        return; //continuer jusqua ce que la touche n'est plus appuyé
    } 
    state = States::PUNCH;
}

void CharacterState::SetCrouch()
{
    if(state == States::CROUCH)
    {
        return; //continuer jusqua ce que la touche n'est plus appuyé
    } 
    state = States::CROUCH;
    ResetFrames = true;
}

void CharacterState::SetHit()
{
    state = States::HIT;
    ResetFrames = true;
}

void CharacterState::SetJump()
{
    state = States::JUMP;
    ResetFrames = true;
}

void CharacterState::SetWinner()
{
    state = States::WINNER;
    ResetFrames = true;
}

void CharacterState::SetLoser()
{
    state = States::LOSER;
    ResetFrames = true;
}

void CharacterState::SetStart()
{
    state = States::START;
}

/// @brief /////////////////////////////////////////////////

void CharacterState::Start()
{
    SetStart();
}

void CharacterState::Idle()
{
    SetIdle();
}

void CharacterState::Walk()
{
    SetWalk();
}

void CharacterState::Walkback()
{
    SetWalkback();
}

void CharacterState::Crouch()
{
    SetCrouch();
}

void CharacterState::Jump()
{
    SetJump();
}

void CharacterState::Kick()
{
    SetKick();
}

void CharacterState::Punch()
{
    SetPunch();
}

void CharacterState::Hit()
{
    SetHit();
}

void CharacterState::Winner()
{
    SetWinner();
}

void CharacterState::Loser()
{
    SetLoser();
}

void CharacterState::RegressionTest()
{
    cout << "RegressionTest" << endl;
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetIdle" << endl;
    SetIdle();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetWalk" << endl;
    SetWalk();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetWalkback" << endl;
    SetWalkback();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetCrouch" << endl;
    SetCrouch();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetJump" << endl;
    SetJump();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetKick" << endl;
    SetKick();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetPunch" << endl;
    SetPunch();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetHit" << endl;
    SetHit();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetWinner" << endl;
    SetWinner();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetLoser" << endl;
    SetLoser();
    cout << "Current state: " << GetCurrentStateString() << endl;
    cout << "SetStart" << endl;
    SetStart();
}