#pragma once

/**
 * @brief Lists with possible error during programme execute. 
 */
enum class Error
{
    /// No error, everything is fine!
    No,
    /// Occurs when memory isn't allocated.
    Memory,
    /// Occurs when the index passed to the method extends beyond of the vector.
    Range
};

/// Renaming unsigned int to uint.
using uint = unsigned int;