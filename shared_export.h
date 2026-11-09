
#ifndef SHARED_EXPORT_H
#define SHARED_EXPORT_H

#ifdef WIN32
#ifdef LIBX_EXPORTS
#define LIBX_EXPORT __declspec(dllexport)
#else
#ifndef LIBX_STATIC
#ifdef LIBX_EXPORTS
#define LIBX_EXPORT __declspec(dllexport)
#else
#define LIBX_EXPORT __declspec(dllimport)
#endif
#else
#define LIBX_EXPORT
#endif
#endif
#else
#define LIBX_EXPORT
#endif
#endif // FILE_TOOL_H
