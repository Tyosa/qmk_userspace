{ pkgs ?  import <nixpkgs> {} }:
pkgs.mkShell {
  packages = with pkgs; [
    qmk
    keymapviz
    clang-tools
  ];
}
