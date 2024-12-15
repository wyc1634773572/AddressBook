#ifndef _DEBUG_H_
#define _DEBUG_H_

#define DEBUG

#ifdef DEBUG
#define LOG_INFO(x) cout << x << endl
#else
#define LOG_INFO(x)
#endif

#endif  // _DEBUG_H_