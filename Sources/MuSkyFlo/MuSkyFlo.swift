import Foundation

public struct MuSkyFlo {

    public static let bundle = Bundle.module

    public static func read(_ filename: String,
                            _ ext: String) -> String? {

        guard let path = Bundle.module.path(forResource: filename,
                                            ofType: ext)  else {
            print("🚫 MuSkyFlo couldn't find file: \(filename)")
            return nil
        }
        do {
            return try String(contentsOfFile: path) }
        catch {
            print("🚫 MuSkyFlo \(#function) error:\(error) loading contents of:\(path)")
        }
        return nil
    }

}
