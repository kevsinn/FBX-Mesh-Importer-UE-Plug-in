## How to use:

1. Download the zip archive
2. Unzip the plugin into %PATH_TO_UE5.3%\Engine\Plugins\Marketplace
3. Activate the plugin in the engine via: Edit -> Plugins -> Installed -> Other -> FBXMeshImporter (check the box) -> restart the engine
4. Call the LoadStaticMeshFromFile() node
5. Specify the absolute path to the .fbx file
6. The node returns a Static Mesh Object Reference, which you need to set in the Static Mesh Component via the SetStaticMesh node.
7. Done! The mesh will be displayed when the project is launched.

Translated with DeepL.com (free version)
