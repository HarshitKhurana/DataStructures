
#include "MWayTree.cpp"

int main()
{
    int rootVal;
    cout << "[*] Enter the root of Tree : ";
    cin>>rootVal;

    Node<int> *root = new Node<int>(rootVal);

    takeInputLevelWise(root,rootVal);

    printTreeLevelWise(root);
}

