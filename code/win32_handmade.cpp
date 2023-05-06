#include <windows.h>

LRESULT MainCallBackWindow(HWND Window,UINT Message,WPARAM WParam,LPARAM LParam
)
{

  int Result = 0;
  
switch(Message){

  case WM_SIZE : {

    OutputDebugStringA("WM_SIZE\n");
    break;
  }

  case WM_DESTROY :{

    OutputDebugStringA("WM_DESTROY\n");
    break;
  }

  case WM_CLOSE : {

    OutputDebugStringA("WM_CLOSE\n");
    break;
  }

  case WM_PAINT: {

      PAINTSTRUCT Paint;

      HDC DeviceContext = BeginPaint(Window,&Paint);

          int x = Paint.rcPaint.left;
          int y = Paint.rcPaint.top;
          int width = Paint.rcPaint.right - Paint.rcPaint.left;
          int height = Paint.rcPaint.bottom - Paint.rcPaint.top;
           
          static DWORD color = BLACKNESS;

      PatBlt(DeviceContext,x,y,width,height, color);

        
      if (color == BLACKNESS) {
          color = WHITENESS;
      }
      else {
          color = BLACKNESS;
      }

      EndPaint(Window, &Paint);
      break;
  }

  case WM_ACTIVATEAPP : {
    OutputDebugStringA("WM_ACTIVATEAPP\n");

    break;
  }

  default:{

      Result = DefWindowProcA(Window, Message,WParam,LParam);
    break;
  }
    
} 
 return Result;
}

int WINAPI WinMain(HINSTANCE Instance, HINSTANCE PrevInstance,
    PSTR CommandLine, int ShowCode)
{

    WNDCLASS WindowClass = {};

    WindowClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    WindowClass.lpfnWndProc = MainCallBackWindow;
        WindowClass.hInstance = Instance;
    //WindpwClass.hIcon;    
    WindowClass.lpszClassName = "HandmadeHeroWindowClass";
    
    if (RegisterClass(&WindowClass)) {

        HWND WindowHandle = CreateWindowExA(
            0,
            WindowClass.lpszClassName,
            "Handmade Hero",
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            0,
            0,
            Instance,
            0
        );

        if (WindowHandle)
        {
            MSG Message;

            for (;;)
            {

                BOOL MessageResult = GetMessage(&Message, 0, 0, 0);

                if (MessageResult > 0)
                {
                    TranslateMessage(&Message);
                    DispatchMessage(&Message);
                }
                else
                {
                    break;
                }

            }
        }
        else 
        {

        }
            
    }
    else {

        // Failed
    }
    return 0;
}
