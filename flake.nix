{
  description = "Flake for a R environment";
  inputs = {
    nixpkgs.url = "nixpkgs/nixos-23.05";
    # nixpkgs.url = "nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (system:
        let
          pkgs = import nixpkgs {inherit system;};
        in {

          packages = {
          };

          devShells.default =
            pkgs.mkShell {
              LOCALE_ARCHIVE = if "${system}" == "x86_64-linux" then "${pkgs.glibcLocalesUtf8}/lib/locale/locale-archive" else "";
              R_LIBS_USER = "''"; # to no use users' installed R packages
              nativeBuildInputs = [pkgs.bashInteractive];
              buildInputs = [
                pkgs.qmk
                pkgs.xorg.xev
              ];
            };

          apps = {
            # example of "apps" that could be run with `nix run .\#<name> -- --args`
            testsRepo = let
              testsRepo = pkgs.writeShellApplication {
                name = "testsRepo";
                text = ''
                  echo "simple unit tests:"
                  Rscript --vanilla ${./tests/testthat.R}
                '';
              };
            in {
              type = "app";
              program = "${testsRepo}/bin/testsRepo";
            };
          };
        }
        );
}

