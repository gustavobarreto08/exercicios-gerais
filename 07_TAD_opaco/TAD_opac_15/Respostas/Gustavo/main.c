#include "dracomania.h"

int main(){
    tDracomania *draco;
    draco = CriaDracomania();
    RodaDracomania(draco);
    ImprimeRelatorioDracomania(draco);
    LiberaDracomania(draco);
    return 0;
}