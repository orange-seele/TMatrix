{
  description = "TMatrix fork with fullwidth Japanese character support";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      packages.${system}.default = pkgs.stdenv.mkDerivation {
        pname = "tmatrix-fullwidth";
        version = "1.4";

        src = self;

        nativeBuildInputs = with pkgs; [
          cmake
        ];

        buildInputs = with pkgs; [
          ncurses
        ];

        installPhase = ''
          mkdir -p $out/bin
          install -Dm755 tmatrix $out/bin/tmatrix
        '';

        meta = {
          description = "A terminal Matrix rain effect with fullwidth Japanese character support";
          homepage = "https://github.com/orange-seele/TMatrix";
          license = pkgs.lib.licenses.gpl3Only;
          mainProgram = "tmatrix";
        };
      };
    };
}