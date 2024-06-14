{ pkgs ?  import <nixpkgs> {} }:
pkgs.mkShell {
  packages = [ pkgs.qmk pkgs.keymapviz ];
}
