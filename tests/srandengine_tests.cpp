#include <atomic>
#include <chrono>
#include <condition_variable>
#include <gtest/gtest.h>
#include <future>
#include <memory>

#include "mocks/bms_mock.hpp"
#include "mocks/eletricmotor_mock.hpp"
#include "mocks/feedmotor_mock.hpp"
#include "mocks/feedsensor_mock.hpp"
#include "mocks/hallsensor_mock.hpp"

#include "models/feedingplan.hpp"

#include "statemanager.hpp"

using namespace FM;
using namespace FM::Models;
using namespace FM::Stages;

TEST(StageManager, componentsNotReady)
{    
}