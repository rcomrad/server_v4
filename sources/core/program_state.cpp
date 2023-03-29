#include "program_state.hpp"

#include <utility>

core::ProgramState core::ProgramState::mThis;

core::ProgramState::ProgramState()
    : mRestartState(Restart::NUN),
      mAutoCheckAnswers(false),
      mSetTimeForAnswers(false)
{
}

core::ProgramState&
core::ProgramState::getInstance()
{
    return mThis;
}

void
core::ProgramState::fullReset()
{
    mRestartMutex.lock();
    mRestartState = Restart::FULL;
    mRestartMutex.unlock();
}

void
core::ProgramState::emptyReset()
{
    mRestartMutex.lock();
    mRestartState = Restart::EMPTY;
    mRestartMutex.unlock();
}

// void
// core::ProgramState::repopulateReset()
// {
//     const std::lock_guard<std::mutex> lock(mRestartMutex);
//     mRestartState = Restart::POPULATE;
// }

bool
core::ProgramState::needRestart()
{
    const std::lock_guard<std::mutex> lock(mRestartMutex);
    return mRestartState != Restart::NUN;
}

bool
core::ProgramState::needPopulateDB()
{
    return mRestartState == Restart::FULL;
    // ||
    //        mRestartState == Restart::POPULATE;
}

bool
core::ProgramState::needRemakeDB()
{
    return mRestartState == Restart::FULL || mRestartState == Restart::EMPTY;
}

void
core::ProgramState::startRestart()
{
    mRestartMutex.lock();
}

void
core::ProgramState::endRestart()
{
    mRestartState = Restart::NUN;
    mRestartMutex.unlock();
}

void
core::ProgramState::setCheckAnswers(core::ProgramState::State aTurn)
{
    const std::lock_guard<std::mutex> lock(mCheckMutex);
    mAutoCheckAnswers = aTurn == State::ON;
}

void
core::ProgramState::setSettingTime(core::ProgramState::State aTurn)
{
    const std::lock_guard<std::mutex> lock(mSetTimeMutex);
    mSetTimeForAnswers = aTurn == State::ON;
}

bool
core::ProgramState::isCheckAnswersTurnOn()
{
    const std::lock_guard<std::mutex> lock(mCheckMutex);
    return mAutoCheckAnswers;
}

bool
core::ProgramState::isSetTimeTurnOn()
{
    const std::lock_guard<std::mutex> lock(mSetTimeMutex);
    return mSetTimeForAnswers;
}

void
core::ProgramState::pushSubmition(
    data::Table<data::Submission>&& aSubmition) noexcept
{
    mSubmitionMutex.lock();
    mSubmitionsQueue.push(std::move(aSubmition));
    mSubmitionMutex.unlock();
}

data::Table<data::Submission>
core::ProgramState::getSubmition() noexcept
{
    const std::lock_guard<std::mutex> lock(mSetTimeMutex);
    data::Table<data::Submission> temp = std::move(mSubmitionsQueue.front());
    mSubmitionsQueue.pop();
    return std::move(temp);
}

bool
core::ProgramState::hasSubmition() noexcept
{
    const std::lock_guard<std::mutex> lock(mSetTimeMutex);
    return !mSubmitionsQueue.empty();
}
