{
	inputs = {
		nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
	};
	outputs = { nixpkgs, ... }:
	let systems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
	in {
		packages = builtins.listToAttrs (builtins.map (system: { name = system; value =
		let pkgs = import nixpkgs { inherit system; };
		in { default = pkgs.stdenv.mkDerivation {
			name = "bal";
			version = "v2.0.0";
			src = ./.;
			nativeBuildInputs = with pkgs; [ gnumake gcc ];
			buildPhase = "make build";
			installPhase = "mkdir -p $out/bin && cp out $out/bin/bal";
		};};}) systems );
	};
}
