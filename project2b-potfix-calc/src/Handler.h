#pragma once

#include <stack>
#include <string>
#include "BigInt.h"

namespace mesa
{
  /**
   * A handler for arithmetic operations.
   */
  class Handler {
    public:
      /**
       * Base class destructor.
       */
      virtual ~Handler() = default;

      /**
       * Handle a command using the operands.
       * @param operands a stack of arbitrarily long integers.
       * @param token whose value depends on which command class is executed.
       *        Is either an operand or operator applied to the operands
       * @return true if an executor actually handled the command.
       */
      virtual bool execute(std::stack<BigInt>& operands, const std::string& token) const = 0;
  };

}


