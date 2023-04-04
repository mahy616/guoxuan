
#ifndef VIMO_INFERENCE_EXPORT_H
#define VIMO_INFERENCE_EXPORT_H

#ifdef VIMO_INFERENCE_STATIC_DEFINE
#  define VIMO_INFERENCE_EXPORT
#  define VIMO_INFERENCE_NO_EXPORT
#else
#  ifndef VIMO_INFERENCE_EXPORT
#    ifdef vimo_inference_EXPORTS
        /* We are building this library */
#      define VIMO_INFERENCE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define VIMO_INFERENCE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef VIMO_INFERENCE_NO_EXPORT
#    define VIMO_INFERENCE_NO_EXPORT 
#  endif
#endif

#ifndef VIMO_INFERENCE_DEPRECATED
#  define VIMO_INFERENCE_DEPRECATED __declspec(deprecated)
#endif

#ifndef VIMO_INFERENCE_DEPRECATED_EXPORT
#  define VIMO_INFERENCE_DEPRECATED_EXPORT VIMO_INFERENCE_EXPORT VIMO_INFERENCE_DEPRECATED
#endif

#ifndef VIMO_INFERENCE_DEPRECATED_NO_EXPORT
#  define VIMO_INFERENCE_DEPRECATED_NO_EXPORT VIMO_INFERENCE_NO_EXPORT VIMO_INFERENCE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef VIMO_INFERENCE_NO_DEPRECATED
#    define VIMO_INFERENCE_NO_DEPRECATED
#  endif
#endif

#endif /* VIMO_INFERENCE_EXPORT_H */
