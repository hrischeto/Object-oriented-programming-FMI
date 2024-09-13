#pragma once
#include "SetExpression.h"
#include "Singleton.h"
#include "UnaryOperation.h"
#include "BinaryOperation.h"
#include "StringView.h"

SetExpression* setFactory(StringView str);

