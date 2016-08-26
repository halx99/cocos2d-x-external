#ifndef _GLFW3EXT_H_
#define _GLFW3EXT_H_
#include "glfw3.h"

typedef int GLFWbool;

#ifndef GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#endif
#ifndef GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WGL
#endif
#include "glfw3native.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GLFW_ALPHA_MASK
#define GLFW_ALPHA_MASK 0x00021011
#endif

/*! @brief The function signature for mouse button callbacks extension.
*   @Added by xseekerj
*
*  This is the function signature for mouse button callback functions.
*
*  @param[in] window The window that received the event.
*  @param[in] button The [mouse button](@ref buttons) that was pressed or
*  released.
*  @param[in] action One of `GLFW_PRESS` or `GLFW_RELEASE`.
*  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
*  held down.
*  @param[in] cursor X
*  @param[in] cursor Y
*
*  @sa glfwSetMouseButtonCallback
*
*  @ingroup input
*/
typedef void(*GLFWXmousebuttonfun)(GLFWwindow*, int, int, int, double, double);
typedef GLFWbool(*GLFWXloadImagefun)(void** ppvImage);
typedef void(*GLFWXunloadImagefun)(void* pvImage);
typedef void(*GLFWXdrawImagefun)(HDC hdc, void* pvImage);

GLFWAPI int glfwxInit(void);

GLFWAPI void glfwxTerminate(void);

GLFWAPI void glfwxSetParent(HWND hwndParent);

GLFWAPI void glfwxSetWindowPos(GLFWwindow* handle, int xpos, int ypos, int width, int height);

/*! @brief Sets the mouse button callback.
*   @Added by xseekerj
*  This function sets the mouse button callback of the specified window, which
*  is called when a mouse button is pressed or released.
*
*  When a window loses focus, it will generate synthetic mouse button release
*  events for all pressed mouse buttons.  You can tell these events from
*  user-generated events by the fact that the synthetic ones are generated
*  after the window has lost focus, i.e. `GLFW_FOCUSED` will be false and the
*  focus callback will have already been called.
*
*  @param[in] window The window whose callback to set.
*  @param[in] cbfun The new callback, or `NULL` to remove the currently set
*  callback.
*  @return The previously set callback, or `NULL` if no callback was set or an
*  error occurred.
*
*  @ingroup input
*/
GLFWAPI GLFWXmousebuttonfun glfwxSetMouseButtonCallback(GLFWwindow* window, GLFWXmousebuttonfun cbfunEx);

GLFWAPI void glfwxSetBackgroundDriver(GLFWXloadImagefun imageLoader, GLFWXdrawImagefun imageDrawer, GLFWXunloadImagefun imageUnloader); // TODO: rename function name

#ifdef __cplusplus
}
#endif

#endif

