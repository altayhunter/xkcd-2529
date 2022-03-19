import { argv } from "process";
import { fileURLToPath } from "url";

function isMain(moduleUrl) {
	const modulePath = fileURLToPath(moduleUrl);
	const [_binPath, mainScriptPath] = argv;
	return modulePath === mainScriptPath;
}

export {
	isMain,
};
