/* 

❌ Why it violates OCP?
- Renderer changes every time a new shape appears
- Renderer has multiple reasons to change not following OCP,SRP
- High coupling: Renderer depends on every shape type



*/

class Renderer
{
    public:
        void renderCircle(float x, float y, float radius)
        {
            // code to render circle
        }
        void renderSquare(float x, float y, float side)
        {
            // code to render square
        }
         // ❌ suppose, When you add Triangle, you must modify Renderer:
        void renderTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
        {
            // code to render triangle
        }
};